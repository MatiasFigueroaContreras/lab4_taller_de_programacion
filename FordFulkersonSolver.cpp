#include "FordFulkersonSolver.h"

FordFulkersonSolver::FordFulkersonSolver()
{
}

FordFulkersonSolver::~FordFulkersonSolver()
{
}

int FordFulkersonSolver::solve(FordFulkersonGraph graph)
{
    parent.clear();
    for (int i = 0; i < graph.numNodes; i++)
    {
        FordFulkersonData ffdata;
        parent.push_back(std::make_pair(-1, ffdata));
    }

    int maxFlow = 0;

    while (bfs(graph))
    {
        int pathFlow = INT_MAX;
        for (int arrivalNode = graph.endNode; arrivalNode != graph.startNode; arrivalNode = parent[arrivalNode].first)
        {
            int startingNode = parent[arrivalNode].first;
            FordFulkersonData arrivalNodeData = parent[arrivalNode].second;
            // std::cout << startingNode << " -> " << arrivalNodeData.node << std::endl;
            pathFlow = std::min(pathFlow, graph.ffGraph[startingNode][arrivalNodeData.pos].capacity);
        }

        for (int arrivalNode = graph.endNode; arrivalNode != graph.startNode; arrivalNode = parent[arrivalNode].first)
        {
            int startingNode = parent[arrivalNode].first;
            FordFulkersonData arrivalNodeData = parent[arrivalNode].second;
            graph.ffGraph[startingNode][arrivalNodeData.pos].capacity -= pathFlow;
            graph.ffGraph[arrivalNode][arrivalNodeData.posReverseDirection].capacity += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

bool FordFulkersonSolver::bfs(FordFulkersonGraph graph)
{
    bool visited[graph.numNodes];
    std::memset(visited, 0, sizeof(visited));

    std::queue<int> nodesToExplore;
    nodesToExplore.push(graph.startNode);
    visited[graph.startNode] = true;
    FordFulkersonData empty;
    parent[graph.startNode] = std::make_pair(-1, empty);

    while (!nodesToExplore.empty())
    {
        int startingNode = nodesToExplore.front();
        nodesToExplore.pop();

        for (size_t j = 0; j < graph.ffGraph[startingNode].size(); j++)
        {
            FordFulkersonData arrivalNodeData = graph.ffGraph[startingNode][j];
            if (visited[arrivalNodeData.node] == false && arrivalNodeData.capacity > 0)
            {
                // std::cout << startingNode << " -> " << arrivalNodeData.node << std::endl;
                parent[arrivalNodeData.node] = std::make_pair(startingNode, arrivalNodeData);
                if (arrivalNodeData.node == graph.endNode)
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