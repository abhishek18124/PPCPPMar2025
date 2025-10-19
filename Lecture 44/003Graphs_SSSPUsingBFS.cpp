/*

Computing SSSP using the BFS algorithm in an unweighted graph.

note : each vertex in the graph is an integer in the range [0, n-1].

e.g.

9 12

0  1
0  2
1  3
1  4
2  4
2  5
3  6
4  6
4  7
5  7
6  8
7  8

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> getPath(int u, vector<int>& par) {

	vector<int> ans = {u};
	while (par[u] != -1) {
		u = par[u];
		ans.push_back(u);
	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // commment this out if gr is directed
	}

	int s = 0; // assume node 0 to be source

	queue<int> q;
	q.push(s);

	vector<int> dis(n);
	dis[s] = 0;

	vector<bool> vis(n, false);
	vis[s] = true;

	vector<int> par(n);
	par[s] = -1; // assume parent of src node is -1

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int ngb : adj[cur]) {
			if (!vis[ngb]) {
				vis[ngb] = true;
				q.push(ngb);
				dis[ngb] = dis[cur] + 1; // since we are visiting the ngb cuz of cur, in the bfs tree cur is the parent of ngb
				par[ngb] = cur;
			}
		}

	}

	for (int i = 0; i < n; i++) {
		cout << "dis(" << i << ") = " << dis[i] << endl;
	}

	cout << endl;


	for (int i = 0; i < n; i++) {
		cout << "par(" << i << ") = " << par[i] << endl;
	}

	int dst = 8;

	// construct the path from src to dst using parent map i.e. bfs tree

	vector<int> path = getPath(dst, par);
	for (int node : path) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}