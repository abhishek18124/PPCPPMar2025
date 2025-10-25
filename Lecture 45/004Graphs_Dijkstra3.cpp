/*

note : nodes are numbered from 0 to n - 1

dijkstra's algorithm

e.g.

input :

5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

output :

0 8 5 9 7

*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

const int INF = 1e9;

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

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // comment this out if graph is directed
	}

	int s = 0; // assume node 0 to be the src vertex

	vector<int> dis(n, INF);
	dis[s] = 0;

	vector<bool> expl(n, false);
	set<pair<int, int>> minHeap; // to track nodes which are not yet explored
	minHeap.insert({dis[s], s});

	vector<int> par(n);
	par[s] = -1; // assume parent of src node is -1

	// time : VlogV + ElogV ~ O((V+E)logV) ~ O(ElogV) assuming E > V
	// space: O(V) due to expl(...), minHeap(...)

	while (!minHeap.empty()) {

		// pair<int, int> p = *minHeap.begin();
		// minHeap.erase(minHeap.begin());
		// int dis_cur = p.first;
		// int cur = p.second;

		auto [dis_cur, cur] = *minHeap.begin();
		minHeap.erase(minHeap.begin());

		// for(pair<int, int> pp : adj[cur]) {
		// 	int ngb = pp.first;
		// 	int edgeWgt = pp.second;
		// 	...
		// }

		for (auto [ngb, edgeWgt] : adj[cur]) {
			if (!expl[ngb] and dis[ngb] > dis_cur + edgeWgt) {
				// edge from cur to ngb is tensed to relax that edge
				minHeap.erase({dis[ngb], ngb});
				dis[ngb] = dis_cur + edgeWgt;
				minHeap.insert({dis[ngb], ngb});  // dis[ngb] contains updated distance to ngb
				par[ngb] = cur;
			}
		}

		expl[cur] = true;

	}

	for (int i = 0; i < n; i++) {
		cout << "dis(" << i << ") = " << dis[i] << endl;
	}

	int dst = 3;

	// construct the path from src to dst using parent map i.e. shortest path tree

	vector<int> path = getPath(dst, par);
	for (int node : path) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}