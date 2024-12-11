#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adjList) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adjList);
        }
    }
}

int main() {
    int n = 6; 
    vector<vector<int>> adjList = {
        {1, 2},
        {3},    
        {3},   
        {4, 5},
        {},     
        {}      
    };

    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    dfs(0, visited, adjList);
    cout << endl;
    return 0;
}
