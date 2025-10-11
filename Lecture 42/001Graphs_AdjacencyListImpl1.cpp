/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v (1 <= u, v <= n) where u, v are edge endpoints .

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		// u--; v--; // do this if you want to take the input to 0-based indexing
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if graph is directed
	}

	for (int i = 1; i <= n; i++) { // iterate from 1 to n since we are using 1-based indexing
		// print the ngblist of node i
		cout << "ngb(" << i << ") = ";
		for (int ngb : adj[i]) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	return 0;

}