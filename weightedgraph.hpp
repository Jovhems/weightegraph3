//
//  weightedgraph.hpp
//  weightedgraph13.cpp
//
//  Created by Jovhems Jean-Baptiste on 12/12/24.
//

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <vector>
#include "Vertex.h"

class WeightedGraph {
public:
    WeightedGraph(int maxVertices);
    bool isEmpty() const;
    void addVertex(Vertex* vertex);
    void addEdge(int start, int end, int weight);
    bool isFull() const;
    void DFS(Vertex* vertex);
    void BFS(Vertex* vertex);
    // Add declaration for the new function

protected:
    int indexIs(Vertex* vertex) const;
    void clearMarks();
    void doDFS(Vertex* vertex);
    void doBFS(Vertex* vertex);
    // Add declaration for the new function

private:
    static const int NULL_EDGE = 0;
    int m_numVertices;
    int m_maxVertices;
    std::vector<Vertex*> m_vertices;
    std::vector<std::vector<int>> m_edges;
    std::vector<bool> m_marks;
    // Add variables to keep track of path, path length, and if path exists
};

#endif // WEIGHTEDGRAPH_H
