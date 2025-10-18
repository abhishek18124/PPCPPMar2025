/*

Given an undirected graph, check if there exists a cycle or not.

	e.g.

	3 3

	0 1
	0 2
	1 2

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur, int par, const vector<vector<int>>& adj, vector<bool>& vis) {

	vis[cur] = true;

	for (int ngb : adj[cur]) {
		if (!vis[ngb]) {

			// ngb is not yet visited

			if (dfs(ngb, cur, adj, vis)) {
				// you've found a cycle in the sub-component of ngb
				// therefore you've found a cycle in the component
				// of cur
				return true;
			}

		} else {

			// ngb is already visited

			// check if cur->ngb is a backedge ?

			if (ngb != par) {

				// cur->ngb is a backedge, we've found a cycle
				// in the component of cur

				return true;

			}

		}
	}

	// there is no cycle in the component of cur
	return false;

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if gr is directed
	}

	vector<bool> vis(n, false);
	bool flag = false; // assume no cycle if present

	for (int i = 0; i < n; i++) {

		if (!vis[i]) {

			// check if the component of node i
			// contains a cycle

			if (dfs(i, -1, adj, vis)) {
				flag = true;
				break;
			}

		}

	}

	if (flag) {
		cout << "cycle found" << endl;
	} else {
		cout << "cycle not found" << endl;
	}

	return 0;
}