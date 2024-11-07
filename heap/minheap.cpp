#include <bits/stdc++.h>
using namespace std;

struct minheap {
    vector<int> array;
    int size = 0;

    int parent(int index) {
        return (index - 1)/2;
    }
    int left(int index) {
        return 2*index+1;
    }
    int right(int index) {
        return 2*index + 2;
    }

    void heapify(int index) {
        int smallest = index;
        int l = left(index);
        int r = right(index);
        if (l < size && array[l] < array[smallest]) {
            smallest = l;
        }
        if (r < size && array[r] < array[smallest]) {
            smallest = r;
        }
        if (index != smallest) {
            swap(array[smallest], array[index]);
            heapify(smallest);
        }
    }

    void insert(int num) {
        array.push_back(num);
        size++;
        int index = size - 1;
        while (index != 0 && array[parent(index)] > array[index]) {
            swap(array[index], array[parent(index)]);
            index = parent(index);
        }
    }

    void getmin() {
        if (size>0)
            cout<<array[0]<<endl;
        else
            cout << "heap is empty" << endl;
    }

    int extmin() {
        if (size==0) {
            cout<<"heap is empty" << endl;
            return -1; 
        }
        
        int min = array[0];
        swap(array[0], array[size - 1]);
        array.pop_back();
        size--;
        heapify(0);
        return min;
    }
};

int main() {
    minheap heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.getmin();
    cout<<heap.extmin()<<endl; 
    heap.getmin();
}
