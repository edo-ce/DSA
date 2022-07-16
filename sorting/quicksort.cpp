#include <iostream>
#include <vector>
#include <random>

using namespace std;

int partition(vector<int>& v, int p, int r) {
    int x = v[r], i = p - 1;
    for (int j = p; j < r; ++j) {
        if (v[j] <= x) {
            ++i;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[r]);
    return i+1;
}

void quicksort(vector<int>& v, int p, int r) {
    if (p >= r) return;
    int q = partition(v, p, r);
    quicksort(v, p, q-1);
    quicksort(v, q+1, r);
}

int random(int low, int high) {
    return low + rand() % (high - low + 1);
}

int randomized_partition(vector<int>& v, int p, int r) {
    srand(time(NULL));
    int i = random(p, r);
    cout << i << endl;
    swap(v[i], v[r]);
    return partition(v, p, r);
}

void randomized_quicksort(vector<int>& v, int p, int r) {
    if (p >= r) return;
    int q = randomized_partition(v, p, r);
    randomized_quicksort(v, p, q-1);
    randomized_quicksort(v, q+1, r);
}

pair<int, int> partitionOtt(vector<int>& v, int p, int r) {
    int x = v[r], min = p, eq = p, max = r;
    while (eq < max) {
        if (v[eq] < x) {
            swap(v[min], v[eq]);
            eq++;
            min++;
        } else if (v[eq] == x) {
            eq++;
        } else {
            max--;
            swap(v[max], v[eq]);
        }
    }
    swap(v[max], v[r]);
    return {min, max};
}

void quicksortOtt(vector<int>& v, int p, int r) {
    if (p >= r) return;
    pair<int, int> q = partitionOtt(v, p, r);
    quicksortOtt(v, p, q.first-1);
    quicksortOtt(v, q.second+1, r);
}

void printVect(const vector<int>& v) {
    for (int elem : v)
        cout << elem << " ";
    cout << endl;
}

int main() {
    vector<int> v = {4, 16, 2, 47, 33, 12, 62, 9};
    printVect(v);
    quicksort(v, 0, v.size()-1);
    printVect(v);

    return 0;
}
