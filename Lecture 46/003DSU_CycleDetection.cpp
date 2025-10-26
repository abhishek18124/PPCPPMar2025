/*

cycle detection in an undirected graph using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

4 4

1 2
2 3
3 4
4 1

output :

true

*/

#include<iostream>
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

	vector<vector<int>> edges; // we are treating each edge as a 2-sized vector // you can also represent an edge as pair<int, int>
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
	}

	disjointSet ds(n);
	for (int i = 1; i <= n; i++) { // nodes are labelled from 1 to n
		ds.createSet(i);
	}

	bool flag = false; // assume no cycle present

	for (vector<int> e : edges) { // each edge is a 2-sized vector
		int u = e[0];
		int v = e[1];
		if (ds.findSet(u) != ds.findSet(v)) {
			ds.unionSet(u, v);
		} else {
			// u & v are in the same set i.e.
			// they are part of the same component
			// which means there is already a path b/w
			// them and now we've also have an edge
			// b/w them so we've a cycle
			flag = true;
			break;
		}
	}

	if (flag == false) {
		cout << "no cycle found" << endl;
	} else {
		cout << "cycle found" << endl;
	}

	// time : O(V + E) assuming op. on disjointSet take const time
	// space: O(V) due to disjointSet (par & rank)

	return 0;
}