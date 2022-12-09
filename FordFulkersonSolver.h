#include "FordFulkersonGraph.h"
#include <utility>
#include <queue>
#include <climits>
#include <cstring>

class FordFulkersonSolver
{
private:
    std::vector<std::pair<int, FordFulkersonData>> parent;
public:
    FordFulkersonSolver();
    ~FordFulkersonSolver();
    int solve(FordFulkersonGraph graph);
    bool bfs(FordFulkersonGraph graph);
};
