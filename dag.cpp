#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

bool isDAG(int n, vector<vector<int>> &adjList) {
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

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return count == n;
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

    cout << "Is the graph a DAG? " << (isDAG(n, adjList) ? "Yes" : "No") << endl;

    return 0;
}
