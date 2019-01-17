//
// Created by wojtek on 10.01.19.
//

#include <limits>
#include "NNeighbourSolver.h"

void compute_nn_path(int *values, Problem &problem, int offset){
    int index = rand() % problem.size - offset;
    swap(values[offset],values[offset + index]);
    for (int i=offset; i < offset + problem.size / 2 - 1; i++){
        float best = numeric_limits<float>::max();
        for (int j = i + 1; j < problem.size; j++){
            float distance = problem.distance_matrix[values[i]][values[j]];
            if (distance < best){
                best = distance;
                index = j;
            }
        }
        swap(values[i+1], values[index]);
    }
}

Solution* NNeighbourSolver::solve(Problem& problem) {
    int offset = 0;
    int *values = new int[problem.size];
    for (int i = 0; i < problem.size; i++)
    {
        values[i] = i;
    }

    compute_nn_path(values, problem, offset);
    offset = problem.size / 2;
    compute_nn_path(values, problem, offset);
    return new Solution(problem.size,values);
}