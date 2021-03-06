//
// Created by wojtek on 11.01.19.
//

#ifndef TSP_BENCHMARKRESULT_H
#define TSP_BENCHMARKRESULT_H


#include "../Solution.h"
#include "Similarity.h"

class BenchmarkResult {
public:
    Solution* best_solution;
    vector<Solution*>* solutions;
    double* times;
    float* scores;
    double computation_sec_time;
    vector<SimilarityPoint> similarity_points;

    BenchmarkResult(Solution&, vector<Solution*>&, double, double*, float*, vector<SimilarityPoint>);

};


#endif //TSP_BENCHMARKRESULT_H
