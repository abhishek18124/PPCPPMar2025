/*

The first line contains two integers n and m where n is the number of vertices
and  m is the number of edges. Following m lines contain one edge each in form
u, v where u, v are edge endpoints.

input :

5 6
A B
A C
B D
C D
C E
D E

*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	map<char, vector<char>> adj;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		char u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // comment this out if gr is directed
	}

	for (pair<char, vector<char>> p : adj) {
		char nodeLabel = p.first;
		vector<char> ngbList = p.second;
		cout << "ngb(" << nodeLabel << ") = ";
		for (char ngb : ngbList) {
			cout << ngb << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (auto [nodeLabel, ngbList] : adj) {
		cout << "ngb(" << nodeLabel << ") = ";
		for (char ngb : ngbList) {
			cout << ngb << " ";
		}
		cout << endl;
	}
	cout << endl;



	return 0;

}