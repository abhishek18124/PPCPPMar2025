/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v (0 <= u, v <= n-1) where u, v are edge endpoints .

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<set<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u); // comment this out if graph is directed
	}

	for (int i = 0; i < n; i++) {
		// print the ngblist of node i
		cout << "ngb(" << i << ") = ";
		for (int ngb : adj[i]) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	return 0;

}