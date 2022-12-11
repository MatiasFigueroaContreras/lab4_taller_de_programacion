#include "MBPSolver.h"
#include <ctime>

int main()
{
    clock_t ti, tf;
    double dt = 0;
    MBPSolver solver;
    FordFulkersonGraph graph;
    int res;
    std::string fileName;
    std::cout << "Solucionador de problemas de maxima asignacion bipartita" << std::endl;
    std::cout << "Ingrese el nombre del archivo que contiene el grafo bipartito: ";
    std::cin >> fileName;

    graph = solver.loadGraph(fileName);
    ti = clock();
    res = solver.solve(graph);
    tf = clock();
    dt = (tf - ti) / (double)CLOCKS_PER_SEC;
    std::cout << "La maxima asignacion de pares es: " << res << std::endl;
    std::cout << "Tiempo de ejecucion: " << dt << " segundos" << std::endl;
}
