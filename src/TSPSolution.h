//
// Created by wojtek on 10.12.18.
//

#ifndef TSP_TSPSOLUTION_H
#define TSP_TSPSOLUTION_H

#include <iostream>
#include <map>

enum class SolutionMetadata {
    FIRST_COST,
    STEPS_COUNT,
    SEEN_SOLUTIONS_COUNT
};

using namespace std;
class TSPSolution{
public:
    TSPSolution(map<SolutionMetadata,float>&);

    map< SolutionMetadata,float>* metadata;
};
#endif //TSP_TSPSOLUTION_H
