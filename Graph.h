

#ifndef POOJAALGORITHM_GRAPH_H
#define POOJAALGORITHM_GRAPH_H


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adjList;
public:
    void addVertex(string vertex);
    void addEdge(string u, string v, int weight);
    void BFS(string start, string end);
    void printPath(unordered_map<string, string> &predecessor, string end);
};


#endif //POOJAALGORITHM_GRAPH_H
