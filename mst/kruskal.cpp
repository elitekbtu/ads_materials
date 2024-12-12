#include <bits/stdc++.h>
using namespace std; 

struct DSU{
    vector<int> parent, rank; 
    DSU(int n){
        parent.resize(n, -1);
        rank.resize(n, 1);
    }
    int find(int i){
        if(parent[i]==-1){
            return i
        }
        return parent[i] = find(parent[i]);
    }
    void unite(int u, int v){
        int ru = find(u); 
        int rv = find(v);
        if(ru!=rv){
            if(rank[ru]>rank[rv]){
                parent[rv] = ru;
            }
            else if(parent[ru]<parent[rv]){
                parent[ru] = rv;
            }
            else{
                parent[rv]=ru;
                rank[ru]++;
            }
        }
    }
}; 
struct Edge{
    int u, v, weight; 
    bool operator<(const Edge& other) const{
        return weight < other.weight;
    } 
}
vector<Edge> krsmst(vector <Edge>& edges, int v){
    sort(edges.begin(), edges.end());
    DSU dsu(v);
    vector<Edge> mst;
    for(const auto& edge:edges){
        if(dsu.find(edge.u!=dsu.find(edge.v))){
            dsu.unite(edge.u, edge.v);
            mst.push_back(edge);
        }
    }
    return mst;
}

int main(){
}