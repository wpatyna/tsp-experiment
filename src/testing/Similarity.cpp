//
// Created by wojtek on 20.01.19.
//

#include "Similarity.h"
#include <algorithm>
#include <iterator>


int Similarity::check_cycle(int *solution1, int size1, int *solution2, int size2) {
    int sum = 0;
    for (int i = 0; i < size1; i++) {
        if (
                this->is_pair_the_same(
                        solution1[i],
                        solution1[(i + 1) % size1],
                        solution2[i],
                        solution2[(i + 1) % size2]
                ) ||
                this->is_pair_the_same(
                        solution1[(size1 - i) % size1],
                        solution1[size1 - (i + 1)],
                        solution2[(size2 - i) % size2],
                        solution2[size2 - (i + 1)]
                )
                ) {
            sum += 1;
        }
    }
    return sum;
};


bool Similarity::is_pair_the_same(int s10, int s11, int s20, int s21) {
    return (s10 == s20 && s11 == s21) || (s10 == s21 && s11 == s20);
}

float Similarity::similarity(int size, int *s1, int *s2) {
    int *firstTravellerFirstSequence = new int[size / 2];
    std::copy(s1, s1 + size / 2, firstTravellerFirstSequence);
    int *secondTravellerFirstSequence = new int[size / 2];
    std::copy(s1 + size / 2, s1 + size, secondTravellerFirstSequence);

    int *firstTravellerSecondSequence = new int[size / 2];
    std::copy(s2, s2 + size / 2, firstTravellerSecondSequence);
    int *secondTravellerSecondSequence = new int[size / 2];
    std::copy(s2 + size / 2, s2 + size, secondTravellerSecondSequence);

    return max(
            this->check_cycle(firstTravellerFirstSequence, size / 2, firstTravellerSecondSequence, size / 2)
            + this->check_cycle(secondTravellerFirstSequence, size / 2, secondTravellerSecondSequence, size / 2),

            this->check_cycle(firstTravellerFirstSequence, size / 2, secondTravellerSecondSequence, size / 2)
            + this->check_cycle(secondTravellerFirstSequence, size / 2, firstTravellerSecondSequence, size / 2)
    ) / (float)size;
}


vector<SimilarityPoint> Similarity::get_similarity_points(vector<Solution *> &solutions, Problem &problem) {
    Solution *best_solution = solutions[0];
    for (int i = 0; i < solutions.size(); i++) {
        best_solution = best_solution->compare(*solutions[i], problem) ? solutions[i] : best_solution;
    }
    vector<SimilarityPoint> points;

    for (int i = 0; i < solutions.size(); i++) {
        SimilarityPoint similarityPoint = SimilarityPoint();
        similarityPoint.similarity = this->similarity(problem.size, solutions[i]->solution, best_solution->solution);
        similarityPoint.score = problem.cost_of_path(solutions[i]->solution);
        points.push_back(similarityPoint);
    }

    return points;
}