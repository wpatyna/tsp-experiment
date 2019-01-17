//
// Created by wojtek on 11.01.19.
//

#ifndef TSP_BENCHMARKRESULT_H
#define TSP_BENCHMARKRESULT_H


#include "../Solution.h"

class BenchmarkResult {
public:
    Solution* best_solution;
    Solution* worst_solution;
    vector<Solution*>* solutions;
    double computation_sec_time;

    BenchmarkResult(Solution&, Solution&, vector<Solution*>&, double);

};


#endif //TSP_BENCHMARKRESULT_H
