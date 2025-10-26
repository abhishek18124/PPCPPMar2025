/*

optimising union and find operations using

* union by rank
* path compression

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

	int n;
	cin >> n;

	disjointSet ds(n);

	ds.createSet(1);
	ds.createSet(2);
	ds.createSet(3);
	ds.createSet(4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl;

	ds.unionSet(2, 3);

	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;

	ds.unionSet(1, 4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(4) << endl;

	ds.unionSet(1, 2);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl;

	return 0;

}