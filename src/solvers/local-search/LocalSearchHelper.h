//
// Created by wojtek on 11.01.19.
//

#ifndef TSP_LOCALSEARCHHELPER_H
#define TSP_LOCALSEARCHHELPER_H


#include "../../Solution.h"
#include "../../Problem.h"

class LocalSearchHelper {
public:
    int* compute_solution(int*, Problem&);
    void compute_solution_inplace(int*, Problem&);
private:
    bool is_the_same_cycle(int, int, int);
    float compute_cost_symmetric_change(int*, float **, int, int, int);
    float compute_cost_asymmetric_change(int*, float**, int, int, int);
    void reverseSequence(int *array, int from, int to);
};


#endif //TSP_LOCALSEARCHHELPER_H
