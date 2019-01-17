//
// Created by wojtek on 11.01.19.
//

#include "SolutionInitializer.h"


SolutionInitializer::SolutionInitializer(Solver &solver) {
    this->solver = &solver;
}

Solution *SolutionInitializer::initialize(Problem &problem) {
    return this->solver->solve(problem);
}