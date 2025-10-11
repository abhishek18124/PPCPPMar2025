/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v (0 <= u, v < n) where u, v are edge endpoints .

input :

5 6
0 1
0 2
1 3
2 3
2 4
3 4

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if graph is directed
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