#ifndef PRIM_H
#define PRIM_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include "MinHeap.h"

using namespace std;

class Prim {
private:
    unordered_map<string, vector<pair<string, int>>> adjList;
    unordered_map<string, bool> inTree;
    unordered_map<string, int> key;
    unordered_map<string, string> parent;
    MinHeap minHeap;

public:
    Prim();
    void addVertex(string vertex);
    void addEdge(string u, string v, int weight);
    void primMST(string start);
    void printMST(string start);
};

#endif // PRIM_H
