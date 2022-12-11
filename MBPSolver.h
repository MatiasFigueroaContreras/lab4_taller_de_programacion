#include "FordFulkersonSolver.h"

/*
    (Maximum Bipartite Matching Solver)
    Descripcion de la clase MBPSolver:
    Esta clase busca resolver un problema de maxima
    asignacion bipartita utilizando el Ford-Fulkerson,
    para esto se busca transformar un grafo bipartito
    en uno que incluya un nodo origen y uno de llegada.
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
