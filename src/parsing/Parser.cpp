#include "Parser.h"
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> Parser::split(std::string strToSplit, char delimeter) {
    std::stringstream ss(strToSplit);
    std::string item;
    std::vector<std::string> splittedStrings;
    while (getline(ss, item, delimeter)) {
        if (!item.empty()) {
            splittedStrings.push_back(item);
        }
    }
    return splittedStrings;
}

Problem *Parser::load(string &path) {
    map<string, string> header;
    ifstream infile(path);
    string line;
    while (getline(infile, line) && line.compare("NODE_COORD_SECTION") != 0) {
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        vector<string> splited = split(line, ':');
        header[splited.at(0)] = splited.at(1);
    }
    vector<Node *> nodes = load_nodes(infile);
    Metric *metric = new Metric(header["EDGE_WEIGHT_TYPE"]);
    float **distance_matrix = get_distace_matrix(nodes, *metric);
    int dimension = stoi(header["DIMENSION"]);
    return new Problem(header["NAME"], dimension, distance_matrix);
};

float **Parser::get_distace_matrix(vector<Node *> &nodes, Metric &metric) {
//    vector<vector<float> > matrix;
    int size = int(nodes.size());
    float **matrix = new float *[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new float[size];
        for (int j = 0; j < size; j++) {
            if (i != j) {
                matrix[i][j] = metric.get_distance(*nodes[i], *nodes[j]);
            } else {
                matrix[i][j] = numeric_limits<float>::max();
            }
        }
    }
    return matrix;
}

vector<Node *> Parser::load_nodes(ifstream &reader) {
    string line;
    vector<Node *> node_list;
    while (getline(reader, line) && line.compare("EOF") != 0) {
        vector<string> raw_node = split(line, ' ');
        Node *node = new Node(stoi(raw_node.at(0)), stof(raw_node.at(1)), stof(raw_node.at(2)));
        node_list.push_back(node);
    }
    return node_list;
}
