#include <iostream>
#include <vector>

using namespace std;

void countingsort(vector<int>& v, int k) {
    vector<int> res(v.size(), 0);
    vector<int> occ(k+1, 0);
    for (int i = 0; i < v.size(); ++i) {
        occ[v[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
        occ[i] = occ[i] + occ[i-1];
    }
    for (int i = res.size()-1; i >= 0; --i) {
        res[occ[v[i]]-1] = v[i];
        occ[v[i]]--;
    }
    for (int i = 0; i < v.size(); ++i) {
        v[i] = res[i];
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
    countingsort(v, 62);
    printVect(v);

    return 0;
}
