#include "minheap.hpp"
#include <cmath>
#include <cassert>

using namespace std;

// default constructor
MinHeap::MinHeap() = default;

// create a new heap given an array
MinHeap::MinHeap(const vector<int>& arr) {
    elements = arr;
    for (int i = floor((size()-1)/2); i >= 0; --i)
        heapifyDown(i);
}

// default destructor
MinHeap::~MinHeap() = default;

// return the parent of elements[i]
int MinHeap::parent(int i) {
    return (i - 1) / 2;
}

// return the left child of elements[i]
size_t MinHeap::left(size_t i) {
    return 2 * i + 1;
}

// return the right child of elements[i]
size_t MinHeap::right(size_t i) {
    return 2 * i + 2;
}

// return the size of the heap
size_t MinHeap::size() const {
    return elements.size();
}

void MinHeap::heapifyDown(size_t i) {
    if (i >= size()) return;
    size_t l = left(i);
    size_t r = right(i);
    size_t min = i;
    if (l < size() && elements[l] < elements[min]) {
        min = l;
    }
    if (r < size() && elements[r] < elements[min]) {
        min = r;
    }
    if (min != i) {
        swap(elements[i], elements[min]);
        heapifyDown(min);
    }
}

void MinHeap::heapifyUp(int i) {
    if (i && elements[parent(i)] > elements[i]) {
        swap(elements[i], elements[parent(i)]);
        heapifyUp(parent(i));
    }
}

// check if the heap is empty
bool MinHeap::empty() const {
    return elements.empty();
}

// get the min value
int MinHeap::getMin() const {
    assert(!empty());
    return elements[0];
}

// get the max value
int MinHeap::getMax() const {
    int max = elements[(size_t)floor(size()-1)/2+1];
    for (size_t i = (size_t)floor((size()-1)/2)+2; i < size(); ++i) {
        if (elements[i] > max)
            max = elements[i];
    }
    return max;
}

// get and remove the min value
int MinHeap::extractMin() {
    assert(!empty());
    int min = elements[0];
    elements[0] = elements.back();
    elements.pop_back();
    heapifyDown(0);
    return min;
}

// inset the value k in the heap
void MinHeap::insert(int k) {
    elements.push_back(k);
    heapifyUp((int)size()-1);
}

// remove elements[i]
void MinHeap::remove(size_t i){
    if (i >= size()) return;
    if (size() == 1) {
        elements.pop_back();
    } else {
        int val = elements[i];
        elements[i] = elements.back();
        elements.pop_back();
        if (val < elements[i]) {
            heapifyDown(i);
        } else {
            heapifyUp((int)i);
        }
    }
}

// remove all the elements from the heap
void MinHeap::clear() {
    elements.clear();
}

int MinHeap::auxSearch(int k, size_t node) const {
    if (node >= size() || elements[node] > k) {
        return -1;
    } else if (elements[node] == k) {
        return (int)node;
    } else {
        return max(auxSearch(k, left(node)), auxSearch(k, right(node)));
    }
}

// return the index of k, if k is present, -1 otherwise
int MinHeap::search(int k) const {
    return auxSearch(k, 0);
}

void MinHeap::print() const {
    cout << "[ ";
    for (int elem : elements)
        cout << elem << " ";
    cout << "]" << endl;
}
