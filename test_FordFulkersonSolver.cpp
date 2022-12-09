#include "FordFulkersonSolver.h"

int main()
{
    FordFulkersonGraph ffGraph1 = FordFulkersonGraph("ffgraph1.txt");
    FordFulkersonSolver ffSolver;
    int res = ffSolver.solve(ffGraph1);
    std::cout << "Grafo: " << std::endl;
    ffGraph1.print();
    std::cout << "Maximo Flujo: " << res << std::endl;

    FordFulkersonGraph ffGraph2 = FordFulkersonGraph("ffgraph2.txt");
    res = ffSolver.solve(ffGraph2);
    std::cout << "Grafo: " << std::endl;
    ffGraph2.print();
    std::cout << "Maximo Flujo: " << res << std::endl;
}