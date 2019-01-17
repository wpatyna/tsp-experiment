#ifndef METRIC_H
#define METRIC_H
#include "Node.h"
#include <string>

using namespace std;


class Metric{
    private:
        string type;
    public:
        Metric(string&);
        float get_distance(Node&, Node&);
};

#endif