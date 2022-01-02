#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void breadthFirstTraversal(vector<int> adj[], bool visited[], int n, int current) {
    

    visited[current] = true;

    queue<int> q;
    q.push(current);

    while(!q.empty()) {
        current = q.front();
        q.pop();
        cout << current << " -> ";

        for(int x: adj[current]) {
            if(!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }

    cout << "\n";

}



int main() {
    int n = 4;

    vector<int> adj[n];
    
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);    
    addEdge(adj, 2, 0); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 3); 
  
    bool visited[n];
    for(int i = 0; i < n; i++) visited[i] = false;

    cout << "Following is Breadth First Traversal"
            " (starting from vertex 1) \n"; 
    
    breadthFirstTraversal(adj, visited, n, 1); 

    cout << "\n";

    return 0;
}