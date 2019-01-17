//
// Created by wojtek on 11.01.19.
//

#include "RandomSolver.h"

Solution* RandomSolver::solve(Problem & problem) {
    int *solution = new int[problem.size];
    for (int i = 0; i < problem.size; i++)
    {
        solution[i] = i;
    }
    int temp = 0;
    for (int i = problem.size - 1; i > 0; i--) {
        /* generate index  between 0-i to swap with ith element */
        int index = rand() % (i + 1);

        temp = solution[index];
        solution[index] = solution[i];
        solution[i] = temp;
//        swap(solution[index], solution[i]);
    }
    return new Solution(problem.size,solution);
}