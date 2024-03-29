#include<bits/stdc++.h>


using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void topologicalSort(int current, vector<bool>& visited, stack<int>& order, vector<int> adj[], int N) {
    
    visited[current] = true;
    for(int x: adj[current]) {
        if(!visited[x]) {
            topologicalSort(x, visited, order, adj, N);
        }
    }

    order.push(current);
}



int main() {
    int N = 6;
    vector<int> adj[N];
    addEdge(adj, 5, 2); 
    addEdge(adj, 5, 0); 
    addEdge(adj, 4, 0); 
    addEdge(adj, 4, 1); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 1); 
    
     // Data Structures required: set and stack
    vector<bool> visited(N, false);
    stack<int> order;

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            topologicalSort(i, visited, order, adj, N);
        }
    } 

    cout << "Topological Sort: ";
    while(!order.empty()) {
        cout << order.top() << ", ";
        order.pop();
    }
    cout << endl;

    return 0;
}