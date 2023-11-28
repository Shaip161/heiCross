#include <iostream>
#include "graph.h"
#include "io.h"
#include "stack.h"

int main(int argc, char* argv[]) {
    std::string graph_file = argv[1];
    std::cout << graph_file << std::endl;

    Graph* g = readGraph(graph_file);
    Graph verifier = *g;

    g->sortYArray();
    std::cout << "sorted" << std::endl;

    g->printGraph();
    std::cout << "count crossings" << std::endl;
    std::cout << "number of crossings in g: " << g->countCrossings() << std::endl;

    auto result = bruteForce(*g);
    std::cout << "crossings BRUTE FORCE: " << result.second << std::endl;
    //std::cout << "crossings GREEDY: " << g->Greedy().second << std::endl;

    //g->Median_Heuristic();
    //std::cout << "number of crossings in g: " << g->countCrossings() << std::endl;

    g->Partition();
    g->printGraph();
    g->AP();


    if (g->verifier(verifier)) {
        std::cout << "Graph is valid"<<std::endl;
    }
    else {
        std::cout << "Graph is NOT valid" << std::endl;
    }

    outputOrder(result.first, "../output.txt");


}

