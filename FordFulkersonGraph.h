#include "FordFulkersonData.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

/*
    Descripcion de la clase FordFulkersonGraph:
    Esta clase representa un grafo como lista de adyacencia
    mediante uso de vectores, orientado a la implementacion
    del algoritmo de Ford Fulkerson.
*/
class FordFulkersonGraph
{
private:

public:
    int sourceNode;
    int sinkNode;
    int numNodes;
    std::vector<std::vector<FordFulkersonData>> ffGraph;
    FordFulkersonGraph(std::string fileName);
    FordFulkersonGraph();
    ~FordFulkersonGraph();
    void print();
};
