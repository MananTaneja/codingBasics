#include<bits/stdc++.h>

using namespace std;



void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void depthFirstTraversal(vector<int> adj[], bool visited[], int n, int current) {
    if(visited[current]) return;
    
    visited[current] = true;

    cout << current << " -> ";

    for(int x: adj[current]) {
        if(!visited[x]) {
            depthFirstTraversal(adj, visited, n, x);
        }
    }

    return;

}



int main() {
    int n = 4;

    vector<int> adj[n];
    
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 2, 0); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 3); 
  
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = false;

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    
    depthFirstTraversal(adj, visited, n, 2); 

    cout << "\n";

    return 0;
}