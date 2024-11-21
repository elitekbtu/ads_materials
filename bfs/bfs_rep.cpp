#include <bits/stdc++.h>
using namespace std; 

bool bfs(vector <vector<int>> &adj, vector <bool> &visited, int s, int f){
    queue <int> q; 
    visited[s] = true; 
    q.push(s);
    while(!q.empty()){
        int cur = q.front(); 
        q.pop(); 
        if(cur == f){
            return true;
        }
        for(int i=0; i<adj[cur].size(); ++i){
            if(adj[cur][i] == 1 && !visited[i]){
                visited[i] = true; 
                q.push(i);
            } 
        }
    }
    return false;
}
int main(){
    int n; 
    cin>>n; 
    vector <vector <int>> adj(n, vector<int>(n)); 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>adj[i][j];
        }
    }
    vector <bool> visited(n, false);
    int str, fin; 
    cin>>str>>fin; 
    if(bfs(adj, visited, str, fin)){
        cout<<"connected";
    }
    else{
        cout<<"unconnected";
    }
}