#include<bits/stdc++.h>

using namespace std;


void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void printAdjacencyList(vector<int> adj[], int n) {
    cout << "\n\n\n\n";
    for(int i = 0; i < n; i++) {
        cout << i << ": ";
        for(int v: adj[i]) {
            cout << v << ", ";
        }
        cout << endl;
    }
}


int main() {
    int n;
    cout << "Enter number of vertices: \n";
    cin >> n;
    cout << endl;
    vector<int> adj[n];
    int nEdges;
    cout << "Enter number of edges: \n";
    cin >> nEdges;
    cout << endl;
    cout << "Enter edges between vertices 0 to " << n-1 << "\n"; 
    while(nEdges--) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u , v);
    }

    // Printing Iterative DFS Using stack!

    int start;
    cout << "\nEnter starting vertex:\n";
    cin >> start; 

    stack<int> s;

    s.push(start);
    vector<bool> visited(n, false);
    visited[start] = true;


    cout << "Traversal be like: ";
    while(!s.empty()) {
        int current = s.top();
        s.pop();
        cout << current << ", ";
        for(int x: adj[current]) {
            if(!visited[x]) {
                s.push(x);
                visited[x] = true;
            }
        }
    }

    cout << "\n";
    
    return 0;
}