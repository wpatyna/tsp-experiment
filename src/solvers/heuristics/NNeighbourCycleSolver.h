//
// Created by wojtek on 10.01.19.
//

#ifndef TSP_NNEIGHBOURCYCLESOLVER_H
#define TSP_NNEIGHBOURCYCLESOLVER_H


#include "../Solver.h"
#include "../../Solution.h"

class NNeighbourCycleSolver: public Solver {
        Solution* solve(Problem&);
};


#endif //TSP_NNEIGHBOURCYCLESOLVER_H
