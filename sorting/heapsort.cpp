#include "../heap/maxheap.hpp"
#include <iostream>
#include <vector>

using namespace std;

void heapsort(vector<int>& v) {
    MaxHeap heap(v);
    for (int i = v.size()-1; i >= 0; --i)
        v[i] = heap.extractMax();
}

void printVect(const vector<int>& v) {
    for (int elem : v)
        cout << elem << " ";
    cout << endl;
}

int main() {
    vector<int> v = {4, 16, 2, 47, 33, 12, 62, 9};
    printVect(v);
    heapsort(v);
    printVect(v);

    return 0;
}
