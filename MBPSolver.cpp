#include "MBPSolver.h"

/*
    Metodo: Constructor
    Descripcion: este metodo permite crear un Solucionador
        de problemas de maxima asignacion bipartita.
    Parametros: no posee.
    Retorno: La direccion del objeto creado.
*/
MBPSolver::MBPSolver()
{

}

MBPSolver::~MBPSolver()
{

}

/*
    Metodo: 
    Descripcion: este metodo permite crear un grafo de Ford Fulkerson
        agregando los nodos y aristas necesarias que se presentan en
        el archivo el cual contendra el grafo en el formato de un
        problema bipartito, es decir conexiones entre un grupo
        de nodos a otro.
    Parametros:
        -fileName: nombre del archivo que contiene los datos del grafo.
    Retorno: El grafo Ford Fulkerson
*/
FordFulkersonGraph MBPSolver::loadGraph(std::string fileName)
{
    std::string line;
    std::fstream txtStream(fileName);
    std::stringstream charStream;
    std::string stringNumber;

    if (!txtStream.is_open())
    {
        throw std::invalid_argument("El archivo ingresado no existe.");
    }

    int processor, task, numProcessors, numTasks;
    FordFulkersonGraph graph;
    getline(txtStream, line);
    charStream << line;
    getline(charStream, stringNumber, ' ');
    numProcessors = stoi(stringNumber);
    getline(charStream, stringNumber, ' ');
    numTasks = stoi(stringNumber);
    graph.numNodes = numProcessors + numTasks + 2;
    for (int i = 0; i < graph.numNodes; i++)
    {
        std::vector<FordFulkersonData> edges;
        graph.ffGraph.push_back(edges);
    }
    graph.startNode = 0;
    graph.endNode = graph.numNodes - 1;

    while (getline(txtStream, line))
    {
        charStream.clear();
        charStream << line;
        FordFulkersonData data, dataReverse;
        getline(charStream, stringNumber, ' ');
        processor = stoi(stringNumber) + 1; // Los porcesadores parten de 1 en adelante
        getline(charStream, stringNumber, ' ');
        task = stoi(stringNumber) + numProcessors + 1; // Las tareas parten del numero total de procesadores en adelante
        
        // Informacion de la conexion entre procesador y tarea
        data.capacity = 1;
        data.node = task;
        data.pos = graph.ffGraph[processor].size();
        data.posReverseDirection = graph.ffGraph[task].size();
        dataReverse.capacity = 0;
        dataReverse.node = processor;
        dataReverse.pos = data.posReverseDirection;
        dataReverse.posReverseDirection = data.pos;
        graph.ffGraph[processor].push_back(data);
        graph.ffGraph[task].push_back(dataReverse);
    }

    for(int i = 1; i <= numProcessors; i++)
    {
        FordFulkersonData startingData, startingDataReverse, endData, endDataReverse;
        processor = i;
        task = i + numProcessors;

        // Informacion de la conexion entre el nodo inicial y el procesador
        startingData.capacity = 1;
        startingData.node = processor;
        startingData.pos = graph.ffGraph[graph.startNode].size();
        startingData.posReverseDirection = graph.ffGraph[processor].size();
        startingDataReverse.capacity = 0;
        startingDataReverse.node = graph.startNode;
        startingDataReverse.pos = startingData.posReverseDirection;
        startingDataReverse.posReverseDirection = startingData.pos;
        graph.ffGraph[graph.startNode].push_back(startingData);
        graph.ffGraph[processor].push_back(startingDataReverse);

        // Informacion de la conexion entre la tarea y el nodo final
        startingData.capacity = 1;
        startingData.node = graph.endNode;
        startingData.pos = graph.ffGraph[task].size();
        startingData.posReverseDirection = graph.ffGraph[graph.endNode].size();
        startingDataReverse.capacity = 0;
        startingDataReverse.node = task;
        startingDataReverse.pos = startingData.posReverseDirection;
        startingDataReverse.posReverseDirection = startingData.pos;
        graph.ffGraph[task].push_back(startingData);
        graph.ffGraph[graph.endNode].push_back(startingDataReverse);
    }

    return graph;
}

/*
    Metodo:
    Descripcion: este metodo permite resolver un problema 
        de maxima asignacion bipartita, utilizando el metodo
        de FordFulkerson y el grafo generado.
    Parametros:
        -graph: grafo a resolver.
    Retorno: la maxima asignacion de pares.
*/
int MBPSolver::solve(FordFulkersonGraph graph)
{
    return FordFulkersonSolver().solve(graph);
}
