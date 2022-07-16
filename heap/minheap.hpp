#ifndef DSA_MINHEAP_HPP
#define DSA_MINHEAP_HPP

#include <iostream>
#include <vector>

class MinHeap {
public:
    MinHeap();
    explicit MinHeap(const std::vector<int>& arr);
    ~MinHeap();

    size_t size() const;
    bool empty() const;
    int getMin() const;
    int getMax() const;
    int extractMin();
    void insert(int k);
    void remove(size_t i);
    void clear();
    int search(int k) const;
    void print() const;

private:
    std::vector<int> elements;
    void heapifyDown(size_t i);
    void heapifyUp(int i);
    int auxSearch(int k, size_t node) const;
    static int parent(int i);
    static size_t left(size_t i);
    static size_t right(size_t i);
};

#endif
