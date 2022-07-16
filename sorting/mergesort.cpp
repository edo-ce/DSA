#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void merge(vector<int>& v, int first, int mid, int last) {
    int n1 = mid - first + 1, n2 = last - mid;
    vector<int> left(n1);
    vector<int> right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = v[first + i];
    for (int j = 0; j < n2; j++)
        right[j] = v[mid + j + 1];

    int i = 0, j = 0, k = first;
    while(i < n1 && j < n2) {
        if(left[i]<=right[j]) {
            v[k]=left[i];
            i++;
        }
        else{
            v[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<n1) {
        v[k]=left[i];
        i++;
        k++;
    }

    while(j<n2) {
        v[k]=right[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>& v, int first, int last) {
    if (first < last) {
        int mid = floor((first+last)/2);
        mergesort(v, first, mid);
        mergesort(v, mid+1, last);
        merge(v, first, mid, last);
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
    mergesort(v, 0, v.size()-1);
    printVect(v);

    return 0;
}
