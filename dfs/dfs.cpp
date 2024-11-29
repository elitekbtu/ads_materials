#include <bits/stdc++.h>
using namespace std; 

void dfs(vector<vector<int>> &graph, int v, vector <int> &visited){
    visited[v] = 1; 
    for(int to:graph[v]){
        if(!visited[to])
            dfs(graph, to, visited);
    }
};

int main(){

}