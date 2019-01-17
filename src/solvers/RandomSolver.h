//
// Created by wojtek on 11.01.19.
//

#ifndef TSP_RANDOMSOLVER_H
#define TSP_RANDOMSOLVER_H


#include "Solver.h"

class RandomSolver: public Solver {
    Solution* solve(Problem&);
};


#endif //TSP_RANDOMSOLVER_H
