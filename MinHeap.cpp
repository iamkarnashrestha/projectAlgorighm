#include "MinHeap.h"

int MinHeap::parent(int i) {
    return (i - 1) / 2;
}

int MinHeap::left(int i) {
    return 2 * i + 1;
}

int MinHeap::right(int i) {
    return 2 * i + 2;
}

void MinHeap::swap(int i, int j) {
    pair<string, int> temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
    vertexMap[heap[i].first] = i;
    vertexMap[heap[j].first] = j;
}

void MinHeap::heapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap.size() && heap[l].second < heap[i].second)
        smallest = l;
    if (r < heap.size() && heap[r].second < heap[smallest].second)
        smallest = r;
    if (smallest != i) {
        swap(i, smallest);
        heapify(smallest);
    }
}

MinHeap::MinHeap() {}

bool MinHeap::isEmpty() {
    return heap.size() == 0;
}

int MinHeap::size() {
    return heap.size();
}

bool MinHeap::contains(string vertex) {
    return vertexMap.find(vertex) != vertexMap.end();
}

void MinHeap::insert(string vertex, int weight) {
    if (contains(vertex))
        return;
//        throw invalid_argument("Vertex already exists in heap");
    heap.push_back(make_pair(vertex, weight));
    int i = heap.size() - 1;
    vertexMap[vertex] = i;
    while (i != 0 && heap[parent(i)].second > heap[i].second) {
        swap(i, parent(i));
        i = parent(i);
    }
}

pair<string, int> MinHeap::extractMin() {
    if (isEmpty())
        throw invalid_argument("Heap is empty");
    pair<string, int> minVertex = heap[0];
    vertexMap.erase(minVertex.first);
    if (heap.size() == 1) {
        heap.clear();
    } else {
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }
    return minVertex;
}

void MinHeap::decreaseKey(string vertex, int weight) {
    if (!contains(vertex))
        throw invalid_argument("Vertex does not exist in heap");
    int index = vertexMap[vertex];
    if (weight < heap[index].second) {  // Corrected comparison
        heap[index].second = weight;
        while (index > 0 && heap[index].second < heap[parent(index)].second) {
            swap(index, parent(index));
            index = parent(index);
        }
    }
}

void MinHeap::printHeap() {
    for (auto it : heap) {
        cout << "(" << it.first << ", " << it.second << ") ";
    }
    cout << endl;
}
