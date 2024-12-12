#include <bits/stdc++.h>
using namaspace std;
void topsort(int nd, vector<bool> &visited, stack<int> &order, vector<vector<int>> &adj){
    visited[nd] = true; 
    for(int nei:adj[nd]){
        if(!visited[nei]){
            topsort(nei, visited, order, adj)
        }
    }
    order.push(nd);
}

int main(){
    int n; cin>>n;
    vector <vector<int>> adj = {{1,2}, {3}, {3}, {4, 5}, {}, {}};
    stack<int> order;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            topsort(i, visited, order, adj);
        }
    }
    cout<<"topsort"<<endl;
    while(!order.empty()){
        cout<<order.top()<<" ";
        order.pop();
    }
    cout<<endl;
    return 0;
}