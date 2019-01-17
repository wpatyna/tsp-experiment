//
// Created by wojtek on 10.01.19.
//

#include "LocalSearchSteepestSolver.h"

LocalSearchSteepestSolver::LocalSearchSteepestSolver(SolutionInitializer &solution_initializer,
                                                     LocalSearchHelper &helper){
    this->solution_initializer = &solution_initializer;
    this->helper = &helper;

}

Solution *LocalSearchSteepestSolver::solve(Problem &problem) {
    int *solution = this->solution_initializer->initialize(problem)->solution;
    this->helper->compute_solution_inplace(solution,problem);
    return new Solution(problem.size, solution);
}