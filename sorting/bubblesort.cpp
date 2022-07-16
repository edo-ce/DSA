#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& v) {
    bool swapped;
    for (int i = 0; i < v.size()-1; ++i) {
        swapped = false;
        for (int j = 0; j < v.size()-i-1; ++j) {
            if (v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void printVect(const vector<int>& v) {
    for (int elem : v)
        cout << elem << " ";
    cout << endl;
}

int main() {
    vector<int> v = {4, 16, 2, 47, 33, 12, 62, 9};
    printVect(v);
    bubbleSort(v);
    printVect(v);

    return 0;
}
