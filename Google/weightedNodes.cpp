#include<bits/stdc++.h>
using namespace std;

long long int M = 10e9 + 7;
long long int res = 0;

void buildAdj(vector<vector<int>>& graph, vector<pair<int, int>> adj[]) {

    for(vector<int> edge: graph) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u-1].push_back({v-1, w});
        adj[v-1].push_back({u-1, w});
    } 

}

void dfs(vector<pair<int, int>> adj[], vector<bool>& turn, vector<bool>& visited, int current, long long int sum) {
    if(visited[current]) return;

    visited[current] = true;

    for(pair<int, int> p: adj[current]) {
        if(!visited[p.second]){
            int u = current;
            int v = p.first;
            int w = p.second;

            sum += w;

            cout << sum << " ";

            if(!turn[v]) {
                res += sum;
            }

            dfs(adj, turn, visited, v, sum);
        }
    }

}

long long int weightedNodes(vector<vector<int>>& graph, int N) {

    vector<pair<int, int>> adj[N];
    buildAdj(graph, adj);

    vector<bool> turn(N, false);

    for(int i = 0; i < N; i++) {
        vector<bool> visited (N, false); 
        dfs(adj, turn, visited, i, 0);
        turn[i] = true;
        cout << endl;
    }
    cout << endl;
    
    return res;

}


int main() {
    vector<vector<int>> graph;
    graph = {{4, 3, 43}, {5, 6, 12}, {2, 4, 21}, {2, 7, 6}, {6, 3, 66}, {1, 6, 56}};
    int N = 7;
    cout << weightedNodes(graph, N) << endl;

    return 0;
}