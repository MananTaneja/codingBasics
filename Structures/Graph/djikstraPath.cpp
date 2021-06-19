#include<bits/stdc++.h>
using namespace std;

int minIndex(vector<int>& dist, vector<bool>& present) {
    int index = -1;
    int minValue = INT_MAX;
    for(int i = 0; i < dist.size(); i++) {
        if(!present[i] && dist[i] < minValue) {
            index = i;
            minValue = dist[i];
        }
    }
    return index;
}

void printSol(vector<int> &dist){
    cout << "Vertex: Distance from src" << endl;
    for (int i = 0; i < dist.size(); i++)
    {
        cout << i << ": " << dist[i] << endl;
    }
    return;
}

vector<int> djikstraPath(vector<pair<int, int>> adj[], int N, int source) {
    vector<int> dist(N, INT_MAX);
    vector<bool> present(N, false);
    dist[source] = 0;

    for(int i = 0; i < N; i++) {
        int u = minIndex(dist, present);
        present[u] = true;

        for(auto v: adj[u]) {
            if(!present[v.first] && dist[u] != INT_MAX && dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;
            }
        }
    }

    printSol(dist);

    //  Will add code for path later - basically use parent vector and parent[v] = u for every update in the inner most condition
    return {};
}

int main() {
    int N, M;

    cin >> N >> M;

    vector<pair<int, int>> adj[N];

    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    parebrt
    vector<int> path = djikstraPath(adj, N, 0);

    return 0;
}