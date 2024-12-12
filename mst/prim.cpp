#include <bits/stdc++.h>
using namespace std;

#define V 5;

int mink(int key[], bool, mstset[]){
    int min=INF, minidx;
    for(int i=0; i<V; i++){
        if(!mstset[i] && key[v]< min){
            min = key[v]; 
            minidx = v;
        }
    }
    return minidx;
}
void printMST(int parent[], int graph[V][V]) {
    for (int i = 1; i < V; i++)
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << graph[i][parent[i]] << endl;
}
void primmst(int graph[V][V]){
    int parent[V];
    int key[V]; 
    bool mstSet[V];
    for(int i=0; i<V; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0; 
    parent[0] = -1; 
    for(int cnt=0; cnt<v-1; cnt++){
        int u = mink(key, mstSet)
        mstSet[u] = true;

        for(int v=0; i<V; v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]){
                parent[v] = u; 
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}
int main(){
     int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}