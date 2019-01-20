#ifndef PROBLEM_H
#define PROBLEM_H

#include <string>
#include <vector>

using namespace std;

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