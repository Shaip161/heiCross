#include <iostream>
#include "graph.h"
#include "io.h"

int main(int argc, char* argv[]) {
    std::string graph_file = argv[1];
    std::cout << graph_file << std::endl;

    Graph* g = readGraph(graph_file);

    g->sortYArray();
    std::cout << "sorted" << std::endl;

    g->printGraph();
    std::cout << "count crossings" << std::endl;
    std::cout << "number of crossings in g: " << g->countCrossings() << std::endl;

    auto result = bruteForce(*g);
    std::cout << "crossings BRUTE FORCE: " << result.second << std::endl;
    std::cout << "crossings GREEDY: " << g->Greedy().second << std::endl;

    outputOrder(result.first, "../output.txt");
}
