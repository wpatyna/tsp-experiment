//
// Created by wojtek on 12.01.19.
//

#ifndef TSP_EVOLUTIONARYSOLVER_H
#define TSP_EVOLUTIONARYSOLVER_H


#include "../Solver.h"
#include "../local-search/LocalSearchHelper.h"
#include "../local-search/IteratedLocalSearchSteepestSolver.h"

class EvolutionarySolver: public Solver {
public:
    EvolutionarySolver(LocalSearchHelper&, MS);
    Solution* solve(Problem&);
private:
    LocalSearchHelper *local_search_helper;
    MS runtime;
};


#endif //TSP_EVOLUTIONARYSOLVER_H
