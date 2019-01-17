#ifndef PARSER_H
#define PARSER_H
#include "Metric.h"
#include "Node.h"
#include "../Problem.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class Parser{

    private:
        vector<Node*> load_nodes(ifstream &reader);
        float** get_distace_matrix(vector<Node*>&, Metric&);
        vector<string> split(string, char);
    public:
        Problem* load(string &);
};

#endif