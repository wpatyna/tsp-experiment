//
// Created by wojtek on 11.01.19.
//

#include "BenchmarkResult.h"


BenchmarkResult::BenchmarkResult(Solution &best_solution, vector<Solution *> &solutions,
                                 double computation_sec_time, double* times, float* scores, vector<SimilarityPoint> points) {
    this->best_solution = &best_solution;
    this->solutions = &solutions;
    this->computation_sec_time = computation_sec_time;
    this->times = times;
    this->scores = scores;
    this->similarity_points = points;
}
