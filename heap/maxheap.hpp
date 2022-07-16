#ifndef DSA_MAXHEAP_HPP
#define DSA_MAXHEAP_HPP

#include <iostream>
#include <vector>

class MaxHeap {
public:
    MaxHeap();
    explicit MaxHeap(const std::vector<int>& arr);
    ~MaxHeap();

    size_t size() const;
    bool empty() const;
    int getMax() const;
    int getMin() const;
    int extractMax();
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
