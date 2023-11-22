#include "Dijkstra.h"

Dijkstra::Dijkstra() {}

void Dijkstra::addVertex(string vertex) {
    if (adjList.find(vertex) == adjList.end()) {
        adjList[vertex] = vector<pair<string, int>>();
    }
}

void Dijkstra::addEdge(string u, string v, int weight) {
    adjList[u].push_back(make_pair(v, weight));
    adjList[v].push_back(make_pair(u, weight));
}

void Dijkstra::findShortestPath(string start, string end) {
    for (auto it = adjList.begin(); it != adjList.end(); it++) {
        dist[it->first] = INT_MAX;
        parent[it->first] = "";
    }

    dist[start] = 0;

    for (auto it = adjList.begin(); it != adjList.end(); it++) {
        minHeap.insert(it->first, dist[it->first]);
    }

    while (!minHeap.isEmpty()) {
        pair<string, int> minVertex = minHeap.extractMin();
        string u = minVertex.first;

        for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
            string v = it->first;
            int weight = it->second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                minHeap.decreaseKey(v, dist[v]);
            }
        }
    }

    printPath(start, end);
}

void Dijkstra::printPath(string start, string end) {
    vector<string> path;
    while (end != "") {
        path.push_back(end);
        end = parent[end];
    }

    reverse(path.begin(), path.end());

    cout << "Shortest path from " << start << " to " << path.back() << ": ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}
