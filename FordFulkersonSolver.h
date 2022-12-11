#include "FordFulkersonGraph.h"
#include <utility>
#include <queue>
#include <climits>
#include <cstring>

/*
    Descripcion de la clase FordFulkersonSolver:
    Esta clase busca resolver un problema de maximo flujo
    mediante el uso del algoritmo de Ford Fulkerson.
*/
class FordFulkersonSolver
{
private:
    std::vector<std::pair<int, FordFulkersonData>> sinkPath;

public:
    FordFulkersonSolver();
    ~FordFulkersonSolver();
    int solve(FordFulkersonGraph graph);
    bool bfs(FordFulkersonGraph graph);
};
