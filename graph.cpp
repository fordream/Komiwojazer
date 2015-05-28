#include "graph.h"

Graph::Graph(int vertexes): vertexes(vertexes)
{
    this->edges=new double*[vertexes];
    for(int i=0; i<vertexes; i++)
    {
        this->edges[i]=new double[vertexes];
        for(int j=0; j<vertexes; j++)
        {
            this->edges[i][j]=0;
        }
    }
}

void Graph::addEdge(int v1, int v2, double distance)
{
    if(v1<vertexes && v2<vertexes)
    {
        this->edges[v1][v2]=distance;
        this->edges[v2][v1]=distance;
    }
}

double Graph::getEdgeValue(int v1, int v2)
{
    return this->edges[v1][v2];
}

Graph::~Graph()
{
    for(int i=0; i<vertexes; i++)
    {
        delete this->edges[i];
    }
    delete this->edges;
}
