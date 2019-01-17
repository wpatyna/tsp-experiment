//
// Created by wojtek on 11.01.19.
//

#include "LocalSearchHelper.h"


bool LocalSearchHelper::is_the_same_cycle(int size, int i, int j) {
    return (i / (size / 2)) == j / ((size / 2));
}

int get_cycled_index(int index, int size) {
    return ((index % size) + size) % size;
}

float LocalSearchHelper::compute_cost_symmetric_change(int *array, float **distance_matrix, int i, int j, int size) {
    int offset = (i / (size / 2)) * size / 2;

    float delta = 0;
    delta -= distance_matrix[array[get_cycled_index(i - 1, size / 2) + offset]][array[i]];
    delta -= distance_matrix[array[j]][array[get_cycled_index(j + 1, size / 2) + offset]];
    delta += distance_matrix[array[get_cycled_index(i - 1, size / 2) + offset]][array[j]];
    delta += distance_matrix[array[i]][array[get_cycled_index(j + 1, size / 2) + offset]];
    return delta;
}

float LocalSearchHelper::compute_cost_asymmetric_change(int *array, float **distance_matrix, int i, int j, int size) {
    int offset = size / 2;
    float delta = 0;
    delta -= distance_matrix[array[get_cycled_index(i - 1, size / 2)]][array[i]];
    delta -= distance_matrix[array[get_cycled_index(i + 1, size / 2)]][array[i]];
    delta += distance_matrix[array[get_cycled_index(i - 1, size / 2)]][array[j]];
    delta += distance_matrix[array[get_cycled_index(i + 1, size / 2)]][array[j]];

    delta -= distance_matrix[array[j]][array[get_cycled_index(j + 1, size / 2) + offset]];
    delta -= distance_matrix[array[j]][array[get_cycled_index(j - 1, size / 2) + offset]];
    delta += distance_matrix[array[i]][array[get_cycled_index(j + 1, size / 2) + offset]];
    delta += distance_matrix[array[i]][array[get_cycled_index(j - 1, size / 2) + offset]];

    return delta;

}

void LocalSearchHelper::reverseSequence(int *array, int from, int to) {
    int temp = 0;
    for (int k = from, l = to; k < l; k++, l--) {
        temp = array[k];
        array[k] = array[l];
        array[l] = temp;
//        swap(array[k], array[l]);
    }
}

void LocalSearchHelper::compute_solution_inplace(int *solution, Problem &problem) {
    bool flag = true;
    while (flag) {
        int best_i = 0, best_j = 0;
        float max_delta = 0;
        for (int i = 0; i < problem.size - 1; i++) {
            for (int j = i + 1; j < problem.size; j++) {
                float delta = 0;
                if (is_the_same_cycle(problem.size, i, j)) {
                    delta = compute_cost_symmetric_change(solution, problem.distance_matrix, i, j, problem.size);
                } else {
                    delta = compute_cost_asymmetric_change(solution, problem.distance_matrix, i, j, problem.size);
                }
                if (delta < max_delta) {
                    max_delta = delta;
                    best_i = i;
                    best_j = j;
                }
            }
        }
        if (max_delta < -0.001 ){
            if (is_the_same_cycle(problem.size, best_i, best_j)){
                reverseSequence(solution, best_i, best_j);
            }else {
                swap(solution[best_i], solution[best_j]);
            }
        }else{
            flag = false;
        }
    }
}

int *LocalSearchHelper::compute_solution(int *solution, Problem &problem) {
    int *new_solution = new int[problem.size];
    copy(solution, solution + problem.size, new_solution);
    this->compute_solution_inplace(new_solution, problem);
    return new_solution;
}