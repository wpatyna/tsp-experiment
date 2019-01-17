#include "Solution.h"

Solution::Solution(int size, int *solution /*, float score, float initial_distance_from_optimum, TSPSolution& tsp_solution*/){
    this->solution = solution;
    this->size = size;
//    this->score = score;
//    this->initial_score = initial_distance_from_optimum;
//    this->tsp_solution = tsp_solution;
}

bool Solution::compare(Solution &solution2){
    return this->score > solution2.score;
}

float Solution::getScore(){
    return this->score;
}