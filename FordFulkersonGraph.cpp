#include "FordFulkersonGraph.h"

FordFulkersonGraph::FordFulkersonGraph()
{

}

FordFulkersonGraph::FordFulkersonGraph(std::string fileName)
{
    std::string line;
    std::fstream txtStream(fileName);
    std::stringstream charStream;
    std::string stringNumber;

    if(!txtStream.is_open())
    {
        throw std::invalid_argument("El archivo ingresado no existe.");
    }

    int startingNode, arrivalNode;
    getline(txtStream, stringNumber);
    this->numNodes = stoi(stringNumber);
    this->startNode = 0;
    this->endNode = numNodes - 1;
    for (int i = 0; i < numNodes; i++)
    {
        std::vector<FordFulkersonData> edges;
        this->ffGraph.push_back(edges);
    }

    while(getline(txtStream, line))
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

void FordFulkersonGraph::print()
{
    for(size_t i = 0; i < ffGraph.size(); i++)
    {
        for(size_t j = 0; j < ffGraph[i].size(); j++)
        {
            if(ffGraph[i][j].capacity != 0)
            {
                std::cout << i << " -> " << ffGraph[i][j].node << " capacidad: " << ffGraph[i][j].capacity << std::endl;
            }
        }
    }
}