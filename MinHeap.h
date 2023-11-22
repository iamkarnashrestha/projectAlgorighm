//
// Created by Karna Shrestha on 11/21/23.
//


#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

using namespace std;

class MinHeap {
private:
    vector<pair<string, int>> heap;
    unordered_map<string, int> vertexMap;

    int parent(int i);
    int left(int i);
    int right(int i);
    void swap(int i, int j);
    void heapify(int i);

public:
    MinHeap();

    bool isEmpty();
    int size();
    bool contains(string vertex);
    void insert(string vertex, int weight);
    pair<string, int> extractMin();
    void decreaseKey(string vertex, int weight);
    void printHeap();
};

#endif // MINHEAP_H

