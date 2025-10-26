/*

kruskals algorithm using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

7 9

1 2 4
1 3 5
2 4 2
2 5 7
3 4 6
3 6 9
5 6 1
5 7 3
6 7 8

output :

22

*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class disjointSet {

	vector<int> par;
	vector<int> rank;

public:

	disjointSet(int n) {
		par.resize(n + 1); // n+1 cuz we are using 1-based indexing
		rank.resize(n + 1); // n+1 cuz we are usign 1-based indexing
	}

	void createSet(int x) {
		par[x] = x;
		rank[x] = 0;
	}

	int findSet(int x) {
		// base case
		if (par[x] == x) {
			return x;
		}

		// recursive case
		return par[x] = findSet(par[x]); // path compression
	}

	void unionSet(int x, int y) { // union by rank
		int lx = findSet(x);
		int ly = findSet(y);
		if (lx != ly) {

			if (rank[lx] == rank[ly]) {
				rank[lx]++; // you can also do rank[ly]++
			}

			// at this point it is guaranteed rank[lx] and rank[ly] are different

			if (rank[lx] > rank[ly]) {
				par[ly] = lx;
			} else {
				// rank[ly] > rank[lx]
				par[lx] = ly;
			}
		}
	}

};

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> edges; // each edge is represented by a 3-sized vector
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, u, v});
	}

	sort(edges.begin(), edges.end()); // by default sorting is done on the 1st member of the vector<>

	disjointSet ds(n);
	for (int i = 1; i <= n; i++) {
		ds.createSet(i);
	}

	int mstSum = 0;
	vector<vector<int>> ans; // to track mst edges

	for (vector<int> e : edges) {
		int w = e[0];
		int u = e[1];
		int v = e[2];

		if (ds.findSet(u) != ds.findSet(v)) {
			// uv is a safe edge
			// so put it in mst
			mstSum += w;
			ans.push_back(e);
			if (ans.size() == n - 1) {
				// you've built the mst
				break;
			}
			ds.unionSet(u, v);
		} else {
			// uv is not safe, including it will lead to a cycle
			// do nothing ...
		}
	}

	cout << mstSum << endl;

	for (vector<int> e : ans) {
		int w = e[0]; int u = e[1]; int v = e[2];
		cout << u << " " << v << " : " << w << endl;
	}

	// time : V + ElogE + E ~ O(ElogE) assuming E > V
	// space: O(V) due to disjointSet

	return 0;
}