#include <iostream>
#include <vector>
#include "src/parsing/Parser.h"
#include "src/testing/Benchmark.h"
#include <ctime>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>


using namespace std;


int main(int argc, char const *argv[]) {
    /* initialize random seed: */
    srand (time(NULL));

    Parser *parser = new Parser();
    vector<string> file_names = {
            "kroA100.tsp",
            "kroA150.tsp"
    };
    vector<Problem*> problems;
    for (int i = 0; i < file_names.size(); i++) {
        string path = "./resources/tsp/";
        path.append(file_names[i]);
        problems.push_back(parser->load(path));
    }
    Benchmark* benchmark = new Benchmark();

//    benchmark->test_heuristics(problems);
//    benchmark->test_local_search(problems);
//    benchmark->test_iterated_local_search(problems);
    benchmark->test_evolutionary(problems);
}