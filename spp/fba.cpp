#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

bool bellman_ford(int start, int n, vector<tuple<int, int, int>>& edges, vector<int>& distance) {
    distance[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (auto [u, v, w] : edges) {
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (auto [u, v, w] : edges) {
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            return false; // Negative weight cycle detected
        }
    }

    return true;
}

int main() {
    int n, m; // number of nodes and edges
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int start;
    cin >> start;

    vector<int> distance(n, INF);
    if (bellman_ford(start, n, edges, distance)) {
        for (int i = 0; i < n; ++i) {
            cout << "Distance to node " << i << ": " << (distance[i] == INF ? -1 : distance[i]) << endl;
        }
    } else {
        cout << "Graph contains a negative weight cycle." << endl;
    }

    return 0;
}
