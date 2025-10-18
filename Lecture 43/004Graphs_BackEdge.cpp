/*

Given an directed graph, check if there exists a back-edge or not.

	e.g.

	4 4

	0 1
	1 2
	2 3
	3 0

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int cur, const vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& stackState) {

	vis[cur] = true;
	stackState[cur] = true;

	for (int ngb : adj[cur]) {
		if (!vis[ngb]) {
			// ngb is not yet visited
			if (dfs(ngb, adj, vis, stackState)) {
				// you've found a directed cycle in the subcomponent of ngb
				// therefore you've found a directed cycle in the component
				// of cur
				return true;
			}
		} else {
			// ngb is visited

			// check if the directed edge from cur to ngb is a backedge ?

			// cur to ngb will be a backedge only when there is a directed
			// path from ngb to cur

			if (stackState[ngb]) {

				// ngb is present on the function stack therefore there is
				// a directed path from ngb to cur therefore the directed
				// edge from cur to ngb is a backedge hence we've found a
				// cycle

				return true;

			}
		}
	}

	stackState[cur] = false;
	return false; // no directed cycle found in the component of cur node

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v); // gr is directed
	}

	bool flag = false; // assume no directed cycle is present
	vector<bool> vis(n, false);
	vector<bool> stackState(n, false); // stackStack[i] tells if node i is present on the fn call stack or not

	for (int i = 0; i < n; i++) {

		if (!vis[i]) {

			// use dfs to check if a directed cycle is present
			// in the component of node i

			if (dfs(i, adj, vis, stackState)) {
				flag = true;
				break;
			}

		}

	}

	if (flag) {
		cout << "directed cycle found" << endl;
	} else {
		cout << "no directed cycle found" << endl;
	}


	return 0;

}