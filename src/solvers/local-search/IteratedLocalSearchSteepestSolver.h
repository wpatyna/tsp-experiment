//
// Created by wojtek on 10.01.19.
//

#ifndef TSP_ITERATEDLOCALSEARCHSTEEPESTSOLVER_H
#define TSP_ITERATEDLOCALSEARCHSTEEPESTSOLVER_H


#include <chrono>
#include "../Solver.h"
#include "../../SolutionInitializer.h"
#include "LocalSearchHelper.h"

typedef chrono::system_clock SYS_CLOCK;
typedef chrono::milliseconds MS;
typedef chrono::time_point<chrono::system_clock> TIME_PT;

class IteratedLocalSearchSteepestSolver: public Solver {
public:
    IteratedLocalSearchSteepestSolver(SolutionInitializer&, LocalSearchHelper&, MS);
    Solution* solve(Problem&);

private:
    SolutionInitializer* solution_initializer;
    LocalSearchHelper* helper;
    MS runtime;
};


#endif //TSP_ITERATEDLOCALSEARCHSTEEPESTSOLVER_H
