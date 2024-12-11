#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

vector<int> topologicalSortKahn(int n, vector<vector<int>> &adjList) {
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (int neighbor : adjList[i]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (topoOrder.size() != n) {
        throw runtime_error("Graph is not a DAG");
    }

    return topoOrder;
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

    try {
        vector<int> topoOrder = topologicalSortKahn(n, adjList);
        cout << "Topological Sort (Kahn's Algorithm): ";
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    } catch (runtime_error &e) {
        cout << e.what() << endl;
    }

    return 0;
}
