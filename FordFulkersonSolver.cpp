#include "FordFulkersonSolver.h"

/*
    Metodo: Constructor
    Descripcion: este metodo permite crear un solucionador de 
        problemas de maximo flujo mediante el metodo
        de FordFulkerson.
    Parametros: no posee.
    Retorno: La direccion del objeto creado.
*/
FordFulkersonSolver::FordFulkersonSolver()
{
}

FordFulkersonSolver::~FordFulkersonSolver()
{
}

/*
    Metodo: 
    Descripcion: este metodo permite resolver el problema de
        maximo flujo mediante el metodo de Ford Fulkerson.
    Parametros:
        -graph: grafo a resolver.
    Retorno: flujo maximo posible del grafo.
*/
int FordFulkersonSolver::solve(FordFulkersonGraph graph)
{
    sinkPath.clear();
    for (int i = 0; i < graph.numNodes; i++)
    {
        FordFulkersonData ffdata;
        sinkPath.push_back(std::make_pair(-1, ffdata));
    }

    int maxFlow = 0;

    while (bfs(graph))
    {
        int pathFlow = INT_MAX;
        for (int arrivalNode = graph.sinkNode; arrivalNode != graph.sourceNode; arrivalNode = sinkPath[arrivalNode].first)
        {
            int startingNode = sinkPath[arrivalNode].first;
            FordFulkersonData arrivalNodeData = sinkPath[arrivalNode].second;
            pathFlow = std::min(pathFlow, graph.ffGraph[startingNode][arrivalNodeData.pos].capacity);
        }

        for (int arrivalNode = graph.sinkNode; arrivalNode != graph.sourceNode; arrivalNode = sinkPath[arrivalNode].first)
        {
            int startingNode = sinkPath[arrivalNode].first;
            FordFulkersonData arrivalNodeData = sinkPath[arrivalNode].second;
            graph.ffGraph[startingNode][arrivalNodeData.pos].capacity -= pathFlow;
            graph.ffGraph[arrivalNode][arrivalNodeData.posReverseDirection].capacity += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

/*
    Metodo:
    Descripcion: este metodo permite buscar y saber si existe un 
        camino posible en el grafo desde un punto de partida
        hasta un punto final, esto utilizando el metodo de 
        busqueda en anchura.
    Parametros:
        -graph: grafo en el cual se buscara un posible camino.
    Retorno: 
        -true: si es que existe un camino posible.
        -false: si NO existe un camino posible.
*/
bool FordFulkersonSolver::bfs(FordFulkersonGraph graph)
{
    bool visited[graph.numNodes];
    std::memset(visited, 0, sizeof(visited));

    std::queue<int> nodesToExplore;
    nodesToExplore.push(graph.sourceNode);
    visited[graph.sourceNode] = true;
    FordFulkersonData empty;
    sinkPath[graph.sourceNode] = std::make_pair(-1, empty);

    while (!nodesToExplore.empty())
    {
        int startingNode = nodesToExplore.front();
        nodesToExplore.pop();

        for (size_t j = 0; j < graph.ffGraph[startingNode].size(); j++)
        {
            FordFulkersonData arrivalNodeData = graph.ffGraph[startingNode][j];
            if (visited[arrivalNodeData.node] == false && arrivalNodeData.capacity > 0)
            {
                sinkPath[arrivalNodeData.node] = std::make_pair(startingNode, arrivalNodeData);
                if (arrivalNodeData.node == graph.sinkNode)
                {
                    return true;
                }
                nodesToExplore.push(arrivalNodeData.node);
                visited[arrivalNodeData.node] = true;
            }
        }
    }

    return false;
}
