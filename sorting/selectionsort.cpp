#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& v) {
    for (int i = 0; i < v.size() - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[min])
                min = j;
        }
        swap(v[min], v[i]);
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
    selectionSort(v);
    printVect(v);

    return 0;
}
