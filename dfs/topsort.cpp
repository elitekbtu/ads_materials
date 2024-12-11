#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void topologicalSortDFS(int node, vector<bool> &visited, stack<int> &order, vector<vector<int>> &adjList) {
    visited[node] = true;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            topologicalSortDFS(neighbor, visited, order, adjList);
        }
    }
    order.push(node);
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
    stack<int> order;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSortDFS(i, visited, order, adjList);
        }
    }

    cout << "Topological Sort (DFS-based): ";
    while (!order.empty()) {
        cout << order.top() << " ";
        order.pop();
    }
    cout << endl;

    return 0;
}
