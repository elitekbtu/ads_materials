#include <bits/stdc++.h>
using namespace std;

int bin_search(vector<int> array, int key) {
    int l = 0;
    int r = array.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (array[m] == key) {
            return m;
        }
        else if (array[m] > key) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> array = {1, 4, 5, 6, 2, 3, 4, 5};
    sort(array.begin(), array.end());

    cout << bin_search(array, 0) << endl; 
    cout << bin_search(array, 1) << endl;
    return 0;
}
