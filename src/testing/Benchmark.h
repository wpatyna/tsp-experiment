//
// Created by wojtek on 10.01.19.
//

#ifndef TSP_BENCHMARK_H
#define TSP_BENCHMARK_H


#include "BenchmarkResult.h"
#include "../solvers/Solver.h"

class Benchmark {
public:
    BenchmarkResult* test(Solver&, Problem&, int);
    void test_heuristics(vector<Problem*>&);
    void test_local_search(vector<Problem*>&);
    void test_iterated_local_search(vector<Problem *> &);
    void test_evolutionary(vector<Problem *> &);
};

#endif //TSP_BENCHMARK_H
