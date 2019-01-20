//
// Created by wojtek on 10.01.19.
//

#include "Benchmark.h"
#include "../solvers/RandomSolver.h"
#include "../SolutionInitializer.h"
#include "../solvers/local-search/LocalSearchSteepestSolver.h"
#include "../solvers/heuristics/NNeighbourSolver.h"
#include "../solvers/local-search/IteratedLocalSearchSteepestSolver.h"
#include "../solvers/evolutionary/EvolutionarySolver.h"


void Benchmark::test_heuristics(vector<Problem *> &problems) {
    NNeighbourSolver *nn_solver = new NNeighbourSolver();
    NNeighbourSolver *nn_cycle_solver = new NNeighbourSolver();
    for (int i = 0; i < problems.size(); i++) {
        BenchmarkResult *nn_result = test(*nn_solver, *problems[i], 10);
        BenchmarkResult *nn_cycle_result = test(*nn_cycle_solver, *problems[i], 10);
    }

}

void Benchmark::test_local_search(vector<Problem *> &problems) {
    LocalSearchHelper *ls_helper = new LocalSearchHelper();

    RandomSolver *random = new RandomSolver();
    SolutionInitializer *random_initializer = new SolutionInitializer(*random);
    LocalSearchSteepestSolver *ls_solver_with_random_input = new LocalSearchSteepestSolver(*random_initializer,
                                                                                           *ls_helper);

    NNeighbourSolver *nn_solver = new NNeighbourSolver();
    SolutionInitializer *nn_initializer = new SolutionInitializer(*nn_solver);
    LocalSearchSteepestSolver *ls_solver_with_heuristic_input = new LocalSearchSteepestSolver(*nn_initializer,
                                                                                              *ls_helper);
    for (int i = 0; i < problems.size(); i++) {
        BenchmarkResult *result_with_random_input = test(*ls_solver_with_random_input, *problems[i], 10);
        BenchmarkResult *result_with_heuristic_input = test(*ls_solver_with_heuristic_input, *problems[i], 10);
        cout << problems[i]->name << ": "
             << problems[i]->cost_of_path(result_with_random_input->best_solution->solution) << ", "
             << problems[i]->cost_of_path(result_with_heuristic_input->best_solution->solution) << endl;
    }

}

void Benchmark::test_iterated_local_search(vector<Problem *> &problems) {
    LocalSearchHelper *ls_helper = new LocalSearchHelper();

    RandomSolver *random = new RandomSolver();
    SolutionInitializer *random_initializer = new SolutionInitializer(*random);
    LocalSearchSteepestSolver *ls_solver_with_random_input = new LocalSearchSteepestSolver(*random_initializer,
                                                                                           *ls_helper);

    IteratedLocalSearchSteepestSolver *ils_solver_with_random_input = nullptr;
    for (int i = 0; i < problems.size(); i++) {
        BenchmarkResult *ls_result = test(*ls_solver_with_random_input, *problems[i], 100);

        int time_ms = int(ls_result->computation_sec_time * 1000);
        MS runtime(time_ms);
//        cout << "time_ms: " << time_ms;
        ils_solver_with_random_input = new IteratedLocalSearchSteepestSolver(*random_initializer, *ls_helper, runtime);
        BenchmarkResult *ils_result = test(*ils_solver_with_random_input, *problems[i], 1);
        cout << problems[i]->name << ": " << problems[i]->cost_of_path(ls_result->best_solution->solution) << ", "
             << problems[i]->cost_of_path(ils_result->best_solution->solution) << endl;

    }
}


void Benchmark::test_evolutionary(vector<Problem *> &problems) {
    LocalSearchHelper *ls_helper = new LocalSearchHelper();

    RandomSolver *random = new RandomSolver();
    SolutionInitializer *random_initializer = new SolutionInitializer(*random);
    LocalSearchSteepestSolver *ls_solver_with_random_input = new LocalSearchSteepestSolver(*random_initializer,
                                                                                           *ls_helper);

    IteratedLocalSearchSteepestSolver *ils_solver_with_random_input = nullptr;
    EvolutionarySolver *evolutionarySolver = nullptr;
    for (int i = 0; i < problems.size(); i++) {
        BenchmarkResult *ls_result = test(*ls_solver_with_random_input, *problems[i], 100);
//
        int time_ms = int(ls_result->computation_sec_time * 1000);
        MS runtime(time_ms);
//
        ils_solver_with_random_input = new IteratedLocalSearchSteepestSolver(*random_initializer, *ls_helper, runtime);
        BenchmarkResult *ils_result = test(*ils_solver_with_random_input, *problems[i], 1);

        evolutionarySolver = new EvolutionarySolver(*ls_helper, runtime);
        BenchmarkResult *evolutonary_result = test(*evolutionarySolver, *problems[i], 1);

        cout << problems[i]->name << ": " << problems[i]->cost_of_path(ls_result->best_solution->solution) << ", "
             << problems[i]->cost_of_path(ils_result->best_solution->solution) << ", "
             << problems[i]->cost_of_path(evolutonary_result->best_solution->solution)
             << endl;

    }
};


BenchmarkResult *Benchmark::test(Solver &solver, Problem &problem, int fire_times) {
    int count = 0;
    struct timespec start, finish;
    double elapsed = 0;
    double current_time = 0;
    vector<Solution *> solutions;
    Solution *best_solution = nullptr;
    do {

        clock_gettime(CLOCK_MONOTONIC, &start);
        Solution *solution = solver.solve(problem);
        clock_gettime(CLOCK_MONOTONIC, &finish);

        count++;
        current_time = (finish.tv_sec - start.tv_sec);
        current_time += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
        solution->time = current_time;

        elapsed += (finish.tv_sec - start.tv_sec);
        elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

        solutions.push_back(solution);
        if (!best_solution) {
            best_solution = solution;
        } else {
            best_solution = best_solution->compare(*solution, problem) ? solution : best_solution;
        }
//        cout << count << endl;
    } while (count < fire_times);

    double* times = new double[fire_times];

    for (int i=0;i < fire_times; i++){
        times[i] = solutions[i]->time;
    }

    float* scores = new float[fire_times];


    for (int i=0;i < fire_times; i++){
        scores[i] = problem.cost_of_path(solutions[i]->solution);
    }

    return new BenchmarkResult(
            *best_solution,
            solutions,
            elapsed,
            times,
            scores
    );
}