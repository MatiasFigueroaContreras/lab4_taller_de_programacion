#include "MBPSolver.h"

int main()
{
    MBPSolver solver;
    FordFulkersonGraph graph = solver.loadGraph("bpgraph1.txt");
    graph.print();

    int res = solver.solve(graph);
    std::cout << "Respuesta: " << res << std::endl;

    graph = solver.loadGraph("bpgraph2.txt");
    graph.print();

    res = solver.solve(graph);
    std::cout << "Respuesta: " << res << std::endl;
}
