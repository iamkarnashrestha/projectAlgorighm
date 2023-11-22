


#include "Graph.h"
    void Graph::addVertex(std::string vertex)  {
        if (adjList.find(vertex) == adjList.end()) {
            adjList[vertex] = vector<pair<string, int>>();
        }
    }

    void Graph::addEdge(string u, string v, int weight) {
        if (adjList.find(u) != adjList.end() && adjList.find(v) != adjList.end()) {
            adjList[u].push_back(make_pair(v, weight));
            adjList[v].push_back(make_pair(u, weight));
        } else {
            cerr << "One or both vertices do not exist: " << u << ", " << v << endl;
        }
    }

    void Graph::BFS(string start, string end) {
        queue<string> q;
        unordered_map<string, bool> visited;
        unordered_map<string, string> predecessor;

        q.push(start);
        visited[start] = true;
        predecessor[start] = "";

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            for (auto &neighbor : adjList[curr]) {
                string nextVertex = neighbor.first;
                if (!visited[nextVertex]) {
                    q.push(nextVertex);
                    visited[nextVertex] = true;
                    predecessor[nextVertex] = curr;

                    if (nextVertex == end) {
                        printPath(predecessor, end);
                        return;
                    }
                }
            }
        }

        cout << "Path not found!" << endl;
    }

    void Graph::printPath(unordered_map<string, string> &predecessor, string end) {

        if (predecessor[end] == "") {
            cout << end;
            return;
        }
        printPath(predecessor, predecessor[end]);
        cout << " -> " << end;
    }

