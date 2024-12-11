#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }
};

int findParent(int node, vector<int> &parent) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}

void unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int kruskal(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n), rank(n, 0);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int mstWeight = 0;
    for (const Edge &edge : edges) {
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            mstWeight += edge.weight;
            unionSets(edge.u, edge.v, parent, rank);
            cout << "Edge included: " << edge.u << " - " << edge.v << " (Weight: " << edge.weight << ")\n";
        }
    }

    return mstWeight;
}

int main() {
    int n = 4; 
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    int mstWeight = kruskal(n, edges);
    cout << "Total weight of MST: " << mstWeight << endl;

    return 0;
}
