//
//  main.cpp
//  weightedgraph13.cpp
//
//  Created by Jovhems Jean-Baptiste on 12/12/24.
//

#include <iostream>
#include "Vertex.h"
#include "WeightedGraph.h"

using namespace std;

int main() {
    // Create a weighted graph with 10 nodes
    WeightedGraph myGraph(10);

    // Define vertices
    Vertex *aVertex, *bVertex, *cVertex, *dVertex, *eVertex;

    // Initialize and add vertices to the graph
    aVertex = new Vertex("A"); // Node 0
    myGraph.addVertex(aVertex);

    bVertex = new Vertex("B"); // Node 1
    myGraph.addVertex(bVertex);

    cVertex = new Vertex("C"); // Node 2
    myGraph.addVertex(cVertex);

    dVertex = new Vertex("D"); // Node 3
    myGraph.addVertex(dVertex);

    eVertex = new Vertex("E"); // Node 4
    myGraph.addVertex(eVertex);

    // Add edges between nodes
    myGraph.addEdge(0, 2, 12);
    myGraph.addEdge(0, 3, 60);
    myGraph.addEdge(1, 0, 10);
    myGraph.addEdge(2, 1, 20);
    myGraph.addEdge(2, 3, 32);
    myGraph.addEdge(4, 0, 7);

    // Perform Depth-First Search (DFS)
    cout << "DFS: ";
    myGraph.DFS(eVertex);
    cout << endl;

    // Perform Breadth-First Search (BFS)
    cout << "BFS: ";
    myGraph.BFS(eVertex);
    cout << endl;

    // Add statements to test the function
    // that checks if a path exists between two nodes

    return 0;
}
