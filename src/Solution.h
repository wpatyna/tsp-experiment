#ifndef SOLUTION_H
#define SOLUTION_H
#include <string>
#include <vector>
#include "TSPSolution.h"
#include "Problem.h"

using namespace std;

class Solution{
    public:

        double time;
        double mean_time;
        double stdev_time;
        float score;
        float initial_score;
        double effectivencess;
        double stdev_effectivencess;
        double mean_effectivencess;
        double mean_steps_count;
        double stdev_steps_count;
        double mean_seen_solutions_count;
        double stdev_seen_solutions_count;
        vector<int> entry_solution;
        int *solution;
        int size;
//        TSPSolution tsp_solution;
        bool compare(Solution&, Problem&);
        Solution(int, int*/*, float, float, TSPSolution&*/);
        float getScore();
};
#endif