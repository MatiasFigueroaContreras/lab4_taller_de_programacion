#include "FordFulkersonData.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

class FordFulkersonGraph
{
private:

public:
    int startNode;
    int endNode;
    int numNodes;
    std::vector<std::vector<FordFulkersonData>> ffGraph;
    FordFulkersonGraph(std::string fileName);
    FordFulkersonGraph();
     ~FordFulkersonGraph();
    void print();
};
