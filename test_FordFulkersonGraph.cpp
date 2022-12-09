#include "FordFulkersonGraph.h"

int main()
{
    FordFulkersonGraph *ffGraph = new FordFulkersonGraph("ffgraph1.txt");

    std::cout << "Grafo: " << std::endl;
    ffGraph->print();
}