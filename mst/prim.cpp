#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> Edge;

int prim(int n, vector<vector<Edge>> &adjList) {
    priority_queue<Edge, vector<Edge>, greater<>> pq;
    vector<bool> inMST(n, false);
    int mstWeight = 0;

    pq.push({0, 0}); 

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (inMST[node]) continue;

        inMST[node] = true;
        mstWeight += weight;

        cout << "Node included in MST: " << node << " (Weight: " << weight << ")\n";

        for (const auto &neighbor : adjList[node]) {
            if (!inMST[neighbor.second]) {
                pq.push(neighbor);
            }
        }
    }

    return mstWeight;
}

int main() {
    int n = 4;
    vector<vector<Edge>> adjList = {
        {{1, 10}, {2, 6}, {3, 5}},
        {{0, 10}, {3, 15}},        
        {{0, 6}, {3, 4}},          
        {{0, 5}, {1, 15}, {2, 4}} 
    };

    int mstWeight = prim(n, adjList);
    cout << "Total weight of MST: " << mstWeight << endl;

    return 0;
}
