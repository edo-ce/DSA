#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingsort(vector<int>& v, int digit) {
    vector<int> res(v.size(), 0);
    vector<int> occ(10, 0);
    for (int i = 0; i < v.size(); ++i) {
        occ[(v[i]/digit)%10]++;
    }
    for (int i = 1; i < 10; ++i) {
        occ[i] = occ[i] + occ[i-1];
    }
    for (int i = res.size()-1; i >= 0; --i) {
        res[occ[(v[i]/digit)%10]-1] = v[i];
        occ[(v[i]/digit)%10]--;
    }
    for (int i = 0; i < v.size(); ++i)
        v[i] = res[i];
}

void radixsort(vector<int>& v) {
    int max = *max_element(v.begin(), v.end());
    for (int i = 1; max / i > 0; i*=10)
        countingsort(v, i);
}

void printVect(const vector<int>& v) {
    for (int elem : v)
        cout << elem << " ";
    cout << endl;
}

int main() {
    vector<int> v = {4, 16, 2, 47, 33, 12, 62, 9};
    printVect(v);
    radixsort(v);
    printVect(v);

    return 0;
}
