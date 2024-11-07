#include <bits/stdc++.h>
using namespace std;

struct maxheap {
    vector<int> array;
    int size = 0;

    int parent(int index) {
        return (index - 1) / 2;
    }
    int left(int index) {
        return 2 * index + 1;
    }
    int right(int index) {
        return 2 * index + 2;
    }

    void heapify(int index) {
        int largest = index;
        int l = left(index);
        int r = right(index);

        if (l < size && array[largest] < array[l]) {
            largest = l;
        }
        if (r < size && array[largest] < array[r]) {
            largest = r;
        }
        if (index != largest) {
            swap(array[largest], array[index]);
            heapify(largest);
        }
    }

    void insert(int num) {
        array.push_back(num);
        size++;
        int index = size - 1;
        while (index != 0 && array[parent(index)] < array[index]) {
            swap(array[index], array[parent(index)]);
            index = parent(index);
        }
    }

    void getmax() {
        if (size>0)
            cout<<array[0]<<endl;
        else
            cout <<"heap is empty"<< endl;
    }

    int extmax() {
        if (size==0) {
            cout<<"heap is empty"<<endl;
            return -1;
        }
        
        int max = array[0];
        swap(array[0], array[size - 1]);
        array.pop_back();
        size--;
        heapify(0);
        return max;
    }
};

int main() {
    maxheap heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.getmax();
    cout<<heap.extmax();
    heap.getmax();
}
