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

using namespace std;

const int INF = 1e9;

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
	for (int i = 0; i < n; i++) {
		minHeap.insert({dis[i], i});
	}
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
				auto it = minHeap.find({dis[ngb], ngb});
				minHeap.erase(it);
				dis[ngb] = dis_cur + edgeWgt;
				minHeap.insert({dis[ngb], ngb});  // dis[ngb] contains updated distance to ngb
			}
		}

		expl[cur] = true;

	}

	for (int i = 0; i < n; i++) {
		cout << "dis(" << i << ") = " << dis[i] << endl;
	}

	return 0;
}