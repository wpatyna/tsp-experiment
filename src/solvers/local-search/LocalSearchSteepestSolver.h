//
// Created by wojtek on 10.01.19.
//

#ifndef TSP_LOCALSEARCHGREEDYSOLVER_H
#define TSP_LOCALSEARCHGREEDYSOLVER_H


#include "../Solver.h"
#include "../../SolutionInitializer.h"
#include "LocalSearchHelper.h"

class LocalSearchSteepestSolver : public Solver {
private:
    SolutionInitializer *solution_initializer;
    LocalSearchHelper *helper;
public:
    LocalSearchSteepestSolver(SolutionInitializer &, LocalSearchHelper &);

    Solution *solve(Problem &);

};


#endif //TSP_LOCALSEARCHGREEDYSOLVER_H
