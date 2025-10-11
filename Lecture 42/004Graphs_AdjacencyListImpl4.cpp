/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v and w where u, v are edge endpoints and w is weight of the edge.

input :

5 6
A B 7
A C 1
B D 2
C D 9
C E 6
D E 5

*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	map<char, vector<pair<char, int>>> adj;
	for (int i = 0; i < m; i++) {
		char u, v;
		cin >> u >> v;
		int w;
		cin >> w;
		adj[u].push_back({v, w}); // adj[u].push_back(make_pair(v, w));
		adj[v].push_back({u, w}); // comment this out if the gr is directed
	}

	for (auto [nodeLabel, ngbList] : adj) {
		cout << "ngb(" << nodeLabel << ") = ";
		for (auto [ngbLabel, edgeWgt] : ngbList) {
			cout << "(" << ngbLabel << ", " << edgeWgt << ") ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;

}