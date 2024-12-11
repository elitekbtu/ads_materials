#include <bits/stdc++.h>
using namespace std; 

bool isdag(int n, vector<vector<int>> &adj){
    vector <int> degree(n, 0);
    for(int i=0; i<n; i++){
        for(int nei:adj[i]){
            degree[nei]++;
        }
    }
    queue <int> q; 
    for(int i=0; i<n; i++){
        if(degree[i]==0){
            q.push(i);
        }
    }
    int cnt=0; 
    while(!q.empty()){
        int nd = q.front();
        q.pop(); 
        cnt++;
        
        for(int nei:adj[nd]){
            degree[nei]--;
            if(degree[nei]==0){
                q.push(nei);
            }
        }
    }
    return n==cnt;
}

int main(){
    int n; cin>>n;
    vector <vector<int>> adj = {{1,2}, {3}, {3}, {4, 5}, {}, {}};
    cout<<isdag(n, adj);
    return 0;
}