#include "FordFulkersonData.h"
#include <iostream>

int main()
{
    FordFulkersonData data;
    data.capacity = 1;
    data.node = 0;
    data.pos = 3;
    data.posReverseDirection = 2;
    std::cout << "Capacidad de la arista: " << data.capacity << std::endl;
    std::cout << "Nodo de llegada de la arista: " << data.node << std::endl;
    std::cout << "Posicion de la matriz en la que se ubica la arista: " << data.pos << std::endl;
    std::cout << "Posicion de la matriz en la que se ubica la arista en sentido contrario: " << data.posReverseDirection << std::endl;
}
