#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int>& distance) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [dist, node] = pq.top();
        pq.pop();

        if (dist > distance[node]) continue;

        for (auto [neighbor, weight] : graph[node]) {
            if (distance[node] + weight < distance[neighbor]) {
                distance[neighbor] = distance[node] + weight;
                pq.push({distance[neighbor], neighbor});
            }
        }
    }
}

int main() {
    int n, m; // number of nodes and edges
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // Remove this line for directed graphs
    }

    int start;
    cin >> start;

    vector<int> distance(n, INF);
    dijkstra(start, graph, distance);

    for (int i = 0; i < n; ++i) {
        cout << "Distance to node " << i << ": " << (distance[i] == INF ? -1 : distance[i]) << endl;
    }

    return 0;
}
