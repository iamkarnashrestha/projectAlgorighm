

#include "Graph.h"
#include "Dijkstra.h"
#include "Prim.h"
#include <fstream>
#include <sstream>

int main() {
    Graph g;
    Dijkstra dijkstra;
    Prim prim;

    // Read vertices from RomaniaVertices.txt
    ifstream verticesFile("/Users/karna/Downloads/PoojaAlgorithm/RomaniaVertices.txt");
    string vertex;
    while (getline(verticesFile, vertex)) {
        // Assuming each line in RomaniaVertices.txt represents a vertex
        g.addVertex(vertex);
        dijkstra.addVertex(vertex);
      prim.addVertex(vertex);
    }
    verticesFile.close();

    // Read edges from RomaniaEdges.txt
    ifstream edgesFile("/Users/karna/Downloads/PoojaAlgorithm/RomaniaEdges.txt");
    string edgeInfo;
    while (getline(edgesFile, edgeInfo)) {
        stringstream ss(edgeInfo);
        string vertex1, vertex2;
        int weight;
        getline(ss, vertex1, ',');
        getline(ss, vertex2, ',');
        ss >> weight;

        g.addVertex(vertex1);
        g.addVertex(vertex2);
        g.addEdge(vertex1, vertex2, weight);

        dijkstra.addVertex(vertex1);
        dijkstra.addVertex(vertex2);
        dijkstra.addEdge(vertex1, vertex2, weight);

        prim.addVertex(vertex1);
        prim.addVertex(vertex2);
        prim.addEdge(vertex1, vertex2, weight);
    }
    edgesFile.close();

    // Perform BFS
    cout << "Shortest path from Arad to Sibiu:" << endl;
    g.BFS("Arad", "Sibiu");
    cout << endl;

    cout << "Shortest path from Arad to Craiova:" << endl;
    g.BFS("Arad", "Craiova");
    cout << endl;

    cout << "Shortest path from Arad to Bucharest:" << endl;
    g.BFS("Arad", "Bucharest");
    cout << endl<<endl;

  //   Perform Dijkstra's Algorithm
    cout << "Dijkstra's Algorithm" << endl;
    dijkstra.findShortestPath("Arad", "Bucharest");
    cout << endl<<endl;
//
//    // Perform Prim's Algorithm
    cout << "Prim's Minimum Spanning Tree:" << endl;
    prim.primMST("Arad");

    return 0;
}
