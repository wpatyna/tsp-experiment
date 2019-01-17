#ifndef PROBLEM_H
#define PROBLEM_H

#include "Solution.h"
#include "TSPSolution.h"
#include <string>
#include <vector>

using namespace std;

typedef TSPSolution *(*AlgorithmFunction)(int *, float **, double, int);

class Problem {
public:
    string name;
    int size;
    float **distance_matrix;

    Problem(string &, int, float **);

    float cost_of_path(int *);
//        Solution* solve(TSPSolution* (*algorithm)(int*, float**, double, int), double);
};

#endif