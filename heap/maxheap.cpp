#include "maxheap.hpp"
#include <cmath>
#include <cassert>

using namespace std;

// default constructor
MaxHeap::MaxHeap() = default;

// create a new heap given an array
MaxHeap::MaxHeap(const vector<int>& arr) {
    elements = arr;
    for (int i = floor((size()-1)/2); i >= 0; --i)
        heapifyDown(i);
}

// default destructor
MaxHeap::~MaxHeap() = default;

// return the parent of elements[i]
int MaxHeap::parent(int i) {
    return (i - 1) / 2;
}

// return the left child of elements[i]
size_t MaxHeap::left(size_t i) {
    return 2 * i + 1;
}

// return the right child of elements[i]
size_t MaxHeap::right(size_t i) {
    return 2 * i + 2;
}

// return the size of the heap
size_t MaxHeap::size() const {
    return elements.size();
}

void MaxHeap::heapifyDown(size_t i) {
    if (i >= size()) return;
    size_t l = left(i);
    size_t r = right(i);
    size_t max = i;
    if (l < size() && elements[l] > elements[max]) {
        max = l;
    }
    if (r < size() && elements[r] > elements[max]) {
        max = r;
    }
    if (max != i) {
        swap(elements[i], elements[max]);
        heapifyDown(max);
    }
}

void MaxHeap::heapifyUp(int i) {
    if (i && elements[parent(i)] < elements[i]) {
        swap(elements[i], elements[parent(i)]);
        heapifyUp(parent(i));
    }
}

// check if the heap is empty
bool MaxHeap::empty() const {
    return elements.empty();
}

// get the max value
int MaxHeap::getMax() const {
    assert(!empty());
    return elements[0];
}

// get the min value
int MaxHeap::getMin() const {
    int min = elements[(size_t)floor(size()-1)/2+1];
    for (size_t i = (size_t)floor((size()-1)/2)+2; i < size(); ++i) {
        if (elements[i] < min)
            min = elements[i];
    }
    return min;
}

// get and remove the max value
int MaxHeap::extractMax() {
    assert(!empty());
    int max = elements[0];
    elements[0] = elements.back();
    elements.pop_back();
    heapifyDown(0);
    return max;
}

// inset the value k in the heap
void MaxHeap::insert(int k) {
    elements.push_back(k);
    heapifyUp((int)size()-1);
}

// remove elements[i]
void MaxHeap::remove(size_t i){
    if (i >= size()) return;
    if (size() == 1) {
        elements.pop_back();
    } else {
        int val = elements[i];
        elements[i] = elements.back();
        elements.pop_back();
        if (val > elements[i]) {
            heapifyDown(i);
        } else {
            heapifyUp((int)i);
        }
    }
}

// remove all the elements from the heap
void MaxHeap::clear() {
    elements.clear();
}

int MaxHeap::auxSearch(int k, size_t node) const {
    if (node >= size() || elements[node] < k) {
        return -1;
    } else if (elements[node] == k) {
        return (int)node;
    } else {
        return max(auxSearch(k, left(node)), auxSearch(k, right(node)));
    }
}

// return the index of k, if k is present, -1 otherwise
int MaxHeap::search(int k) const {
    return auxSearch(k, 0);
}

void MaxHeap::print() const {
    cout << "[ ";
    for (int elem : elements)
        cout << elem << " ";
    cout << "]" << endl;
}
