#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> adj[n];

    // cout << n << m << k;

	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u-1].push_back({v-1, w});
		adj[v-1].push_back({u-1, w});
	}

	// vector<int> dist(n, INT_MAX);
	// dist[0] = 0;

	// if(visited.find()) //O(1)
	set<pair<int, int>> visited;

	queue<int> q;
	vector<vector<int>> dp(n, vector<int>(k+1, 9999999));
	q.push(0);

	for(int i = 0; i <= k; i++) {
		dp[0][i] = 0;
	}
    cout << "Hi!";

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(auto edge: adj[u]) {
			int v = edge.first;
			int w = edge.second;
			pair<int, int> p = make_pair(u, v);
			if(visited.find(p) != visited.end()) {
				continue;
			}
            cout << visited.size() << " "; 
			for(int i = 0; i <= k; i++) {
				if(i == 0) {
					dp[v][i] = min(dp[v][i], dp[u][i] + w);
				}
				else {
					dp[v][i] = min(dp[v][i], min(dp[u][i-1], dp[u][i] + w));
				}
				
			}
			q.push(v);
		}
		
	}

	for(int i = 0; i < n; i++) {
		cout << dp[i][k] << " ";
	}

	return 0;
}