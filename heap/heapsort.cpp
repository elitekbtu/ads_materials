#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& array, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && array[left] > array[largest]) {
        largest = left;
    }
    if (right < n && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(array, n, largest); 
    }
}

void heapsort(vector<int>& array, int n) {
    for (int i = (n / 2 - 1); i >= 0; i--) {
        heapify(array, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

int main() {
    vector<int> array = {1, 3, 3, 4, 5, 7, 8, 6, 1, 4};
    int n = array.size();

    heapsort(array, n);

    for (int i = 0; i < n; i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}
