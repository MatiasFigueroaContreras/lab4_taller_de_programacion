#include "FordFulkersonSolver.h"

/*
    Maximum Bipartite Matching
*/
class MBPSolver
{
private:
    
public:
    MBPSolver();
    ~MBPSolver();
    FordFulkersonGraph loadGraph(std::string fileName);
    int solve(FordFulkersonGraph graph);
};