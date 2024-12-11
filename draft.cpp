#include <bits/stdc++.h>
using namespace std; 

vector<int> topsortkahn(int n, vector<vector<int>> &adj){
    vector <int> degree(n, 0);
    for(int i=0; i<n; i++){
        for(int nei:adj[i]){
            degree[nei]++;
        }
    }

    queue<int> q; 
    for(int i=0; i<n; i++){
        if(degree[i]==0){
            q.push{i};
        }
    }
    vector <int> topord; 
    while(!q.empty()){
        int nd = q.front(); 
        q.pop();
        topord.push_back(nd);
        for(int nei:adj[nd]){
            degree[nei]--;
        }
        if(degree[nei]==0){
            q.push(nei);
        }
    }
    if(topord.size()!=n){
        cout<<"graph is not dag";
        return NULL;
    }
    return topord;
}
int main(){
    int n; cin>>n;
    vector <vector<int>> adj = {{1,2}, {3}, {3}, {4, 5}, {}, {}};
    vector <int> topord = topsortkahn(n, adj);
    for(int nd:topord){
        cout<<nd<<" ";
    }
    cout<<endl;
    return 0;
}