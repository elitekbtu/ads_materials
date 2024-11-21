#include <bits/stdc++.h> 
using namespace std; 

bool bfs(vector<vector<int>> &adj, vector<bool> &visited, int s, int f){
    queue <int> q; 
    visited[s] = true;
    q.push(s); 
    while(!q.empty()){
        int curr = q.front(); 
        q.pop(); 
        if(curr == f){
            return true;
        }
        for(int nei:adj[curr]){
            if(!visited[nei]){
                visited[nei] = true;
                q.push(nei);
            }
        }
    }
    return true;
}
int main(){
    int n; 
    cin>>n; 
    vector<vector<int>> adj(n, vector<int>(0));
    for(int i=0; i<n; i++){
        int m; 
        cin>>m; 
        for(int j=0; j<m; j++){
            int nei; 
            cin>>nei;
            adj[i].push_back(nei);
        }
    }
    vector<bool> visited(n, false); 
    int start, finish; 
    cin>>start>>finish;
    if(bfs(adj, visited, start, finish)){
        cout<<"Connected";
    }
    else{
        cout<<"unconnected";
    }
}