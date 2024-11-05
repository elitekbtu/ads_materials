#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void quicksort(vector<int>& array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high); 
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

int main() {
    vector<int> array = {10, 7, 8, 9, 1, 5};
    int n = array.size();
    quicksort(array, 0, n - 1);
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
