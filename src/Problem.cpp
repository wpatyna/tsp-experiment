#include "Problem.h"

Problem::Problem(string &name, int size, float **distance_matrix) {
    this->name = name;
    this->size = size;
    this->distance_matrix = distance_matrix;
}

float Problem::cost_of_path(int *path) {
    int offset = size / 2;
    float score = 0;
    for (int i = 0; i < size / 2; i++) {
        score += distance_matrix[path[i]][path[(i + 1) % (size / 2)]];
    }
    for (int i = 0; i < size / 2; i++) {
        score += distance_matrix[path[i + offset]][path[(i + 1) % (size / 2) + offset]];
    }
    return score;
}
//Solution* Problem::solve(TSPSolution* (*algorithm)(int*, float**, double, int), double min_time){
//    int *values = new int[this->size];
//    for (int i = 0; i < this->size; i++)
//    {
//        values[i] = i;
//    }
//    Algorithm::randomTSP(values, this->distance_matrix, min_time, this->size);
//    float initial_score = 0;
//    for (int i = 0 ; i < this->size - 1; i++) {
//        // cout << values.at(i) << endl;
//        initial_score += this->distance_matrix[values[i]][values[i + 1]];
//    }
//    TSPSolution* tsp_solution = algorithm(values, this->distance_matrix, min_time, this->size);
//    float score = 0;
//    for (int i = 0 ; i < this->size; i++){
//        // cout << values.at(i) << endl;
//        score += this->distance_matrix[values[i]][values[(i+1) % size]];
//    }
//
//
//    return new Solution(this->size, values, score, initial_score, *tsp_solution);
//}