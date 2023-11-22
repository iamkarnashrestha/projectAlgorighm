#include "Prim.h"

Prim::Prim() {}

void Prim::addVertex(string vertex) {
    if (adjList.find(vertex) == adjList.end()) {
        adjList[vertex] = vector<pair<string, int>>();
    }
}

void Prim::addEdge(string u, string v, int weight) {
    adjList[u].push_back(make_pair(v, weight));
    adjList[v].push_back(make_pair(u, weight));
}

void Prim::primMST(string start) {
    for (auto it = adjList.begin(); it != adjList.end(); it++) {
        key[it->first] = INT_MAX;
        inTree[it->first] = false;
    }

    minHeap.insert(start, 0);
    key[start] = 0;

    while (!minHeap.isEmpty()) {
        string u = minHeap.extractMin().first;
        inTree[u] = true;

        for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
            string v = it->first;
            int weight = it->second;

            if (!inTree[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                minHeap.insert(v, key[v]);
            }
        }
    }

    printMST(start);
}

void Prim::printMST(string start) {
    cout << "Minimum Spanning Tree (Prim's Algorithm):" << endl;

    for (auto it = adjList.begin(); it != adjList.end(); it++) {
        string v = it->first;
        string u = parent[v];
        int weight = key[v];

        if (u != "") {
            cout << u << " - " << v << " : " << weight << endl;
        }
    }
}

