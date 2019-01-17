//
// Created by wojtek on 11.01.19.
//

#include "BenchmarkResult.h"


BenchmarkResult::BenchmarkResult(Solution &best_solution, Solution &worst_solution, vector<Solution *> &solutions,
                                 double computation_sec_time) {
    this->best_solution = &best_solution;
    this->worst_solution = &worst_solution;
    this->solutions = &solutions;
    this->computation_sec_time = computation_sec_time;
}
