#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<bool>& visited, stack<int>& finish, int cur) {

    if(visited[cur]) return;

    visited[cur] = true;
    for(int v: adj[cur]) {
        if(!visited[v]) {
            dfs(adj, visited, finish, v);
        }
    }
    finish.push(cur);
}

vector<int> path;

void printComponents(vector<int> transpose[], vector<bool>& visited, int cur) {
    if(visited[cur]) return;

    path.push_back(cur);
    visited[cur] = true;

    for(int v: transpose[cur]) {
        if(!visited[v]) {
            printComponents(transpose, visited, v);
        }
    }
}



int main() {
    const int n = 5;
    vector<int> adj[n];

    adj[0] = {1};
    adj[1] = {3, 2};
    adj[2] = {0};
    adj[3] = {4};
    adj[4] = {};

    vector<bool> visited(n, false);

    stack<int> finish;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) dfs(adj, visited, finish, i);
    }

    // while(!finish.empty()) {
    //     cout << finish.top() << " ";
    //     finish.pop();
    // }

    // Transpose of Graph

    vector<int> transpose[n];

    for(int i = 0; i < n; i++) {
        visited[i] = false;
        for(int j: adj[i]) {
            transpose[j].push_back(i);
        }
    }

    // Printing Transpose Graph

    // for(int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for(int j: transpose[i]) {
    //         cout << j << " ";
    //     } 
    //     cout << endl;
    // }


    while(!finish.empty()) {
        // cout << finish.top() << " ";
        if(!visited[finish.top()]) {
            path.clear();
            printComponents(transpose, visited, finish.top());
            for(int p: path) {
                cout << p << " ";
            }
            cout << endl;
        }
        finish.pop();
    }

    // cout << endl;
    return 0;
}