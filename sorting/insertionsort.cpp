#include <iostream>
#include <vector>

using namespace std;

void insertionsort(vector<int>& v) {
    for (int i = 1; i < v.size(); ++i) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j+1] = key;
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
    insertionsort(v);
    printVect(v);

    return 0;
}
