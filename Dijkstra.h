
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include "MinHeap.h"

using namespace std;

class Dijkstra {
private:
    unordered_map<string, vector<pair<string, int>>> adjList;
    unordered_map<string, int> dist;
    unordered_map<string, string> parent;
    MinHeap minHeap;

public:
    Dijkstra();
    void addVertex(string vertex);
    void addEdge(string u, string v, int weight);
    void findShortestPath(string start, string end);
    void printPath(string start, string end);
};

#endif // DIJKSTRA_H
