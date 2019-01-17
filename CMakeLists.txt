cmake_minimum_required(VERSION 3.6)
project(tsp)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp src/TSPSolution.h src/SolutionMetadata.cpp src/TSPSolution.cpp src/parsing/Metric.cpp src/parsing/Metric.h src/parsing/Node.cpp src/parsing/Node.h src/parsing/Parser.cpp src/parsing/Parser.h src/solvers/Solver.cpp src/solvers/Solver.h src/testing/Benchmark.cpp src/testing/Benchmark.h src/solvers/heuristics/NNeighbourSolver.cpp src/solvers/heuristics/NNeighbourSolver.h src/solvers/heuristics/NNeighbourCycleSolver.cpp src/solvers/heuristics/NNeighbourCycleSolver.h src/solvers/local-search/LocalSearchSteepestSolver.cpp src/solvers/local-search/LocalSearchSteepestSolver.h src/solvers/local-search/IteratedLocalSearchSteepestSolver.cpp src/solvers/local-search/IteratedLocalSearchSteepestSolver.h src/SolutionInitializer.cpp src/SolutionInitializer.h src/solvers/RandomSolver.cpp src/solvers/RandomSolver.h src/testing/BenchmarkResult.cpp src/testing/BenchmarkResult.h src/solvers/local-search/LocalSearchHelper.cpp src/solvers/local-search/LocalSearchHelper.h src/solvers/evolutionary/EvolutionarySolver.cpp src/solvers/evolutionary/EvolutionarySolver.h src/solvers/evolutionary/process/Selection.cpp src/solvers/evolutionary/process/Selection.h src/testing/TestResult.cpp src/testing/TestResult.h)
file(GLOB SOURCES
        src/*.cpp)
file(GLOB RESOURCES
        resources/*.tsp)
add_executable(tsp ${SOURCE_FILES} ${SOURCES})
file(GLOB MY_FILES "./resources/*.tsp")
file(GLOB OPTIMALS "./resources/*.opt.tour")
file(COPY ${OPTIMALS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources/opt)
file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources/tsp)
#
#find_package(PythonLibs 2.7)
#include_directories(${PYTHON_INCLUDE_DIRS})
#link_directories(${PYTHON_INCLUDE_DIRS})
#target_include_directories(tsp PRIVATE ${PYTHON_INCLUDE_DIRS})
#target_link_libraries(tsp ${PYTHON_LIBRARIES})