#include<iostream>
#include<vector>

using namespace std;

class disjointSet {

	vector<int> par;

public:

	disjointSet(int n) {
		par.resize(n + 1); // n+1 cuz we are using 1-based indexing
	}

	void createSet(int x) {
		par[x] = x;
	}

	int findSet(int x) {
		// base case
		if (par[x] == x) {
			return x;
		}

		// recursive case
		return findSet(par[x]);
	}

	void unionSet(int x, int y) {
		int lx = findSet(x);
		int ly = findSet(y);
		if (lx != ly) {
			par[lx] = ly; // par[ly] = lx;
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