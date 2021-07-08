#include<bits/stdc++.h>
using namespace std;

int N = 6;

int pickNext(vector<bool>& visited, vector<int>& dist) {

    int minDist = INT_MAX;
    int minNode = -1;

    for(int i = 0; i < N; i++) {
        if(dist[i] < minDist && !visited[i]) {
            minDist = dist[i];
            minNode = i;
        }
    }

    return minNode;
}

void printPath(vector<int>& parent, int current) {
    cout << current << " ";
    printPath(parent, parent[current]);
}

int main() {
    
    vector<pair<int, int>> adj[N];

    adj[0] = {{4, 4}, {3, 1}, {1, 2}};
    adj[1] = {{0, 2}, {2, 3}, {5, 7}, {3, 3}};
    adj[2] = {{3, 5}, {5, 8}, {1, 3}};
    adj[3] = {{4, 9}, {0, 1}, {1, 3}, {2, 5}};
    adj[4] = {{0, 4}, {3, 9}};
    adj[5] = {{2, 8}, {1, 7}};
    
    int start = 0;
    vector<bool> visited(N, false);
    
    vector<int> parent(N, -1);
    parent[start] = 100;

    vector<int> dist(N, INT_MAX);
    dist[start] = 0;

    for(int count = 0; count < N-1; count++) {
        int u = pickNext(visited, dist);
        if(u == -1) {
            cout << "PickNext Fails" << endl;
            return -1;
        }
        visited[u] = true;
        for(auto p: adj[u]) {
            int v = p.first;
            int w = p.second;

            if(!visited[v] && dist[v] > dist[u] + w) {
                parent[v] = u;
                dist[v] = dist[u] + w;
            }
        }
    }
    
    int totalWeight = 0;
    for(int n: dist) {
        totalWeight += n;
    }

    cout << totalWeight << endl;

    return 0;
}