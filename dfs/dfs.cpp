#include <bits/stdc++.h>
using namespace std; 

void dfs(int nd, vector<bool> &visited, vector<vector<int>>& adj){
    visited[nd] = true; 
    cout<<nd<<" ";
    for(int nei:adj[nd]){
        if(!visited[nei]){
            dfs(nei, visited, adj);
        }
    }
}
int main(){
    int n; cin>>n;
    vector <vector<int>> adj = {{1,2}, {3}, {3}, {4, 5}, {}, {}};
    vector <bool> vs(n, false);
    dfs(0, visited, ad); 
    return 0;
}