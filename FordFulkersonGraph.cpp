#include "FordFulkersonGraph.h"

/*
    Metodo: Constructor
    Descripcion: este metodo permite crear un grafo de Ford Fulkerson
        sin inicializar sus valores.
    Parametros: no posee.
    Retorno: La direccion del objeto creado.
*/
FordFulkersonGraph::FordFulkersonGraph()
{
}

/*
    Metodo: Constructor
    Descripcion: este metodo permite crear un grafo de Ford Fulkerson
        agregando los nodos y aristas necesarias que se presentan en
        el archivo con el nombre dado.
    Parametros:
        -fileName: nombre del archivo que contiene los datos del grafo.
    Retorno: La direccion del objeto creado.
*/
FordFulkersonGraph::FordFulkersonGraph(std::string fileName)
{
    std::string line;
    std::fstream txtStream(fileName);
    std::stringstream charStream;
    std::string stringNumber;

    if (!txtStream.is_open())
    {
        throw std::invalid_argument("El archivo ingresado no existe.");
    }

    int startingNode, arrivalNode;
    getline(txtStream, stringNumber);
    this->numNodes = stoi(stringNumber);
    this->sourceNode = 0;
    this->sinkNode = numNodes - 1;
    for (int i = 0; i < numNodes; i++)
    {
        std::vector<FordFulkersonData> edges;
        this->ffGraph.push_back(edges);
    }

    while (getline(txtStream, line))
    {
        charStream.clear();
        charStream << line;
        FordFulkersonData data, dataReverse;
        getline(charStream, stringNumber, ' ');
        startingNode = stoi(stringNumber);
        getline(charStream, stringNumber, ' ');
        arrivalNode = stoi(stringNumber);
        getline(charStream, stringNumber, ' ');
        data.capacity = stoi(stringNumber);
        data.node = arrivalNode;
        data.pos = this->ffGraph[startingNode].size();
        data.posReverseDirection = this->ffGraph[arrivalNode].size();
        dataReverse.capacity = 0;
        dataReverse.node = startingNode;
        dataReverse.pos = data.posReverseDirection;
        dataReverse.posReverseDirection = data.pos;
        this->ffGraph[startingNode].push_back(data);
        this->ffGraph[arrivalNode].push_back(dataReverse);
    }
}

FordFulkersonGraph::~FordFulkersonGraph()
{
}

/*
    Metodo:
    Descripcion: este metodo permite imprimir por consola el grafo
        tomando en cuenta solo las aristas que tienen capacidad
        mayor a 0.
    Parametros: no posee.
    Retorno: vacio.
*/
void FordFulkersonGraph::print()
{
    for (size_t i = 0; i < ffGraph.size(); i++)
    {
        for (size_t j = 0; j < ffGraph[i].size(); j++)
        {
            if (ffGraph[i][j].capacity > 0)
            {
                std::cout << i << " -> " << ffGraph[i][j].node << " capacidad: " << ffGraph[i][j].capacity << std::endl;
            }
        }
    }
}