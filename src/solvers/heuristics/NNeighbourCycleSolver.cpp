//
// Created by wojtek on 10.01.19.
//

#include <limits>
#include "NNeighbourCycleSolver.h"

void compute_nn_cycle_path(int *values, Problem &problem, int offset) {
    int index = rand() % problem.size - offset;
    swap(values[offset], values[offset + index]);
    for (int i = offset; i < offset + problem.size / 2 - 1; i++) {
        float best = numeric_limits<float>::max();
        for (int j = i + 1; j < problem.size; j++) {
            float tmp_dist =
                    problem.distance_matrix[values[offset]][values[j]] + problem.distance_matrix[values[i]][values[j]];
            if (tmp_dist < best) {
                best = tmp_dist;
                index = j;
            }
        }
        swap(values[i + 1], values[index]);
    }
}

Solution *NNeighbourCycleSolver::solve(Problem &problem) {
    int offset = 0;
    int *values = new int[problem.size];
    for (int i = 0; i < problem.size; i++) {
        values[i] = i;
    }

    compute_nn_cycle_path(values, problem, offset);
    offset = problem.size / 2;
    compute_nn_cycle_path(values, problem, offset);
    return new Solution(problem.size, values);
}