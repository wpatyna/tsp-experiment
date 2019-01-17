//
// Created by wojtek on 11.01.19.
//

#ifndef TSP_SOLUTIONINITIALIZER_H
#define TSP_SOLUTIONINITIALIZER_H


#include "solvers/Solver.h"

class SolutionInitializer {
public:
    SolutionInitializer(Solver &);

    virtual Solution *initialize(Problem &problem);

private:
    Solver* solver;
};


#endif //TSP_SOLUTIONINITIALIZER_H
