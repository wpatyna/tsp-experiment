//
// Created by wojtek on 12.01.19.
//

#include <limits>
#include <bits/stdc++.h>
#include "EvolutionarySolver.h"
#include "../RandomSolver.h"
#include "../../SolutionInitializer.h"

struct Strategy{
    int* solution;
    float score;
};

Strategy* get_best_solution(vector<int *> &generation, Problem &problem) {
    Strategy* strategy = new Strategy();
    strategy->score = numeric_limits<float>::max();
    strategy->solution = nullptr;
    for (int i = 0; i < generation.size(); i++) {
        float current = problem.cost_of_path(generation[i]);
        if (current < strategy->score) {
            strategy->score = current;
            strategy->solution = generation[i];
        }
    }
    return strategy;
}

void populate(std::vector<int *> &empty_generation, Problem& problem) {
    RandomSolver randomSolver = RandomSolver();
    SolutionInitializer *random_initializer = new SolutionInitializer(randomSolver);

    for (int i=0; i < empty_generation.size(); i ++){
        empty_generation[i] = random_initializer->initialize(problem)->solution;
    }
}


void mutate(int *path, int *new_path, int start, int end){
    int min, max;

    do {
        min = rand() % (end-start);
        max = rand() % (end-start);
    } while (min == max);

    if (min > max) {
        swap(min, max);
    }
    int iter = start;

    for (int i = start; i < min + start; i++) {
        new_path[iter] = path[i];
        iter++;
    }

    for (int i = max + start; i >= min + start; i--) {
        new_path[iter] = path[i];
        iter++;
    }

    for (int i = max + 1 + start; i < end; i++) {
        new_path[iter] = path[i];
        iter++;
    }

}

int *mutate(int *path, int size) {
    int *new_path = new int[size];
    mutate(path, new_path,0, size/2);
    mutate(path, new_path,size/2, size);
    return new_path;

}

int *crossover(int *parent1, int *parent2, int size) {

    int *child = new int[size];
    unordered_set<int> visited;
    int iter = 0;
    for (int i = 0; i < size; i++) {
        if (visited.find(parent1[i]) == visited.end()) {
            child[iter] = parent1[i];
            visited.insert(parent1[i]);
            iter++;
        }
        if (visited.find(parent2[i]) == visited.end()) {
            child[iter] = parent2[i];
            visited.insert(parent2[i]);
            iter++;
        }
    }
    return child;
}

int *tournament_select(std::vector<int *> &generation, Problem &problem) {
    int pool_size = rand() % ((int) generation.size() - 2) + 2;
    std::vector<int *> pool;
    pool.resize((unsigned long) pool_size);
    for(int i = 0; i < pool.size(); i ++){
        pool[i] = generation[random() % generation.size()];
    }
    return get_best_solution(pool, problem)->solution;


}


void update(std::vector<int *> &generation, int* child, Problem &problem){
    int worst_solution_index = 0;
    float worst_solution_score = 0;
    for (int i = 0; i < generation.size() ;i++){
        float tmp_score = problem.cost_of_path(generation[i]);
        if (worst_solution_score < tmp_score){
            worst_solution_index = i;
            worst_solution_score = tmp_score;
        }
    }
    if (worst_solution_score > problem.cost_of_path(child)){
        generation[worst_solution_index] = child;
    }
};



EvolutionarySolver::EvolutionarySolver(LocalSearchHelper &helper, MS runtime) {
    this->local_search_helper = &helper;
    this->runtime = runtime;
}

Solution *EvolutionarySolver::solve(Problem &problem) {
    int population_size = int(problem.size * 0.2);

    std::vector<int *> generation;
    generation.resize((unsigned long) population_size);

    populate(generation, problem);

    TIME_PT end = SYS_CLOCK::now() + runtime;
    while (SYS_CLOCK::now() < end) {

        int parent1_id, parent2_id;
        do {
            parent1_id = rand() % population_size;
            parent2_id = rand() % population_size;
        }while (parent1_id == parent2_id);
        int *random_parent1 = generation[parent1_id];
        int *random_parent2 = generation[parent2_id];

        int *child = crossover(random_parent1, random_parent2, problem.size);
        this->local_search_helper->compute_solution_inplace(child, problem);

        update(generation,child, problem);



//        for (int j = 0; j < new_generation.size(); j++) {
//            int *tournament_parent1 = tournament_select(generation, problem);
//            int *tournament_parent2 = tournament_select(generation, problem);
//
//            int *tournament_child = crossover(tournament_parent1, tournament_parent2, problem.size);
//            this->local_search_helper->compute_solution_inplace(tournament_child, problem);
//            new_generation[j] = tournament_child ;
//        }
//        for (int j = 0; j < new_generation.size(); j++) {
//            double normalized_rand = ((double) rand() / (RAND_MAX));
//            if (normalized_rand < 0.3) {
//                new_generation[j] = mutate(new_generation[j], problem.size); //@TODO change mutate for inplace
//                this->local_search_helper->compute_solution_inplace(new_generation[j], problem);
//            }
//        }
//        Strategy* generation_best_strategy = get_best_solution(new_generation, problem);
//        if (generation_best_strategy->score < best_strategy->score){
//            best_strategy = generation_best_strategy;
//            cout << best_strategy->score << endl;
//        }
    }
    Strategy *best_strategy = get_best_solution(generation, problem);

    return new Solution(problem.size, best_strategy->solution);
}