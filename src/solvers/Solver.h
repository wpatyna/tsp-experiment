//
// Created by wojtek on 10.01.19.
//

#ifndef TSP_SOLVER_H
#define TSP_SOLVER_H


#include "../Solution.h"
#include "../Problem.h"

class Solver {

public:
    virtual Solution* solve(Problem&) = 0;
};


#endif //TSP_SOLVER_H
