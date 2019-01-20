//
// Created by wojtek on 20.01.19.
//

#ifndef TSP_SIMILARITY_H
#define TSP_SIMILARITY_H


#include "../Solution.h"

struct SimilarityPoint{
    float similarity;
    float score;
};


class Similarity {

public:
    float similarity(int, int*, int*);
    vector<SimilarityPoint> get_similarity_points(vector<Solution *> &, Problem &);

private:
    bool is_pair_the_same(int, int, int, int);
    int check_cycle(int*, int, int*, int);
    };


#endif //TSP_SIMILARITY_H
