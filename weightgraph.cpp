//
//  weightgraph.cpp
//  weightedgraph13.cpp
//
//  Created by Jovhems Jean-Baptiste on 12/12/24.
//

#include "weightedgraph.h"
#include <iostream>
#include <queue>

WeightedGraph::WeightedGraph(int size) {
    m_numVertices = 0;
    m_maxVertices = size;
    m_vertices.resize(size, nullptr);

    m_marks.resize(size, false);
    m_edges.resize(size, std::vector<int>(size, NULL_EDGE));
}

void WeightedGraph::addVertex(Vertex* aVertex) {
    m_vertices[m_numVertices] = aVertex;

    for (int i = 0; i < m_maxVertices; i++) {
        m_edges[m_numVertices][i] = NULL_EDGE;
        m_edges[i][m_numVertices] = NULL_EDGE;
    }

    m_numVertices++;
}

void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight) {
    int row = indexIs(m_vertices[fromVertex]);
    int column = indexIs(m_vertices[toVertex]);
    m_edges[row][column] = weight;
}

int WeightedGraph::indexIs(Vertex* aVertex) {
    for (int i = 0; i < m_numVertices; i++) {
        if (m_vertices[i] == aVertex) {
            return i;
        }
    }
    return -1;
}

void WeightedGraph::clearMarks() {
    for (int i = 0; i < m_numVertices; i++) {
        m_marks[i] = false;
    }
}

void WeightedGraph::doDFS(Vertex* aVertex) {
    if (aVertex == nullptr) return;

    std::cout << aVertex->getTitle() << " ";
    int ix = indexIs(aVertex);
    m_marks[ix] = true;

    for (int i = 0; i < m_numVertices; i++) {
        int ix2 = indexIs(m_vertices[i]);
        if (m_edges[ix][ix2] != NULL_EDGE && !m_marks[i]) {
            doDFS(m_vertices[i]);
        }
    }
}

void WeightedGraph::DFS(Vertex* aVertex) {
    clearMarks();
    doDFS(aVertex);
}

void WeightedGraph::doBFS(Vertex* aVertex) {
    if (aVertex == nullptr) return;

    std::queue<Vertex*> que;
    int ix = indexIs(aVertex);
    m_marks[ix] = true;
    que.push(aVertex);

    while (!que.empty()) {
        Vertex* node = que.front();
        que.pop();
        std::cout << node->getTitle() << " ";
        ix = indexIs(node);

        for (int i = 0; i < m_numVertices; i++) {
            int ix2 = indexIs(m_vertices[i]);
            if (m_edges[ix][ix2] != NULL_EDGE && !m_marks[ix2]) {
                m_marks[ix2] = true;
                que.push(m_vertices[i]);
            }
        }
    }
}

void WeightedGraph::BFS(Vertex* aVertex) {
    clearMarks();
    doBFS(aVertex);
}
