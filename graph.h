#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
public:
    Graph(int vertexes);
    ~Graph();
    void addEdge(int v1, int v2, double distance);
    double getEdgeValue(int v1, int v2);

private:
    int vertexes;
    double** edges;
};

#endif // GRAPH_H
