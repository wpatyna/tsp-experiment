//
// Created by wojtek on 10.01.19.
//

#include <random>
#include "IteratedLocalSearchSteepestSolver.h"
#include "LocalSearchHelper.h"


int *perturb(int *tour, int size) {
    // Create the random number generator
    int *solution = new int[size];
    random_device rd;
    default_random_engine rng(rd());
    for(int offset = 0; offset < size ; offset+=size/2){
    uniform_int_distribution<int> random_offset(1, size / 2 / 4);
    // Determine random positions
    int pos1 = random_offset(rng);
    int pos2 = pos1 + random_offset(rng);
    int pos3 = pos2 + random_offset(rng);

    int current_index = 0;
        for (int i = offset; i < pos1 + offset; i++) {
            solution[current_index] = tour[i];
            current_index++;
        }
        for (int i = pos3 + offset; i < size/2 + offset; i++) {
            solution[current_index] = tour[i];
            current_index++;
        }
        for (int i = pos2 + offset; i < pos3 + offset; i++) {
            solution[current_index] = tour[i];
            current_index++;
        }
        for (int i = pos1 + offset; i < pos2 + offset; i++) {
            solution[current_index] = tour[i];
            current_index++;
        }
    }

    return solution;
}

IteratedLocalSearchSteepestSolver::IteratedLocalSearchSteepestSolver(SolutionInitializer &solution_initializer,
                                                                     LocalSearchHelper &helper, MS runtime){
    this->solution_initializer = &solution_initializer;
    this->runtime = runtime;
    this->helper = &helper;
}

Solution *IteratedLocalSearchSteepestSolver::solve(Problem &problem) {
    int *new_solution;
    int *current_solution = this->solution_initializer->initialize(problem)->solution;
    float current_solution_score = problem.cost_of_path(current_solution);
    TIME_PT end = SYS_CLOCK::now() + runtime;
    while (SYS_CLOCK::now() < end) {
        perturb(current_solution, problem.size);
        new_solution = this->helper->compute_solution(current_solution, problem);
        float new_solution_score = problem.cost_of_path(new_solution);
        if (new_solution_score < current_solution_score) {
            current_solution = new_solution;
            current_solution_score = new_solution_score;
        }
    }
    return new Solution(problem.size, current_solution);
}