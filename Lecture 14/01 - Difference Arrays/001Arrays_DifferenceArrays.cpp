/*

e.g.

input
5 3
4 1 5 2 3
0 2 5
2 3 2
3 4 7

output
9 6 12 11 10

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, q;
	cin >> n >> q;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> diff(n + 1, 0);
	while (q--) {
		int l, r, x;
		cin >> l >> r >> x;
		diff[l] += x;
		diff[r + 1] -= x;
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << diff[i] << " ";
	// }

	// cout << endl;

	// diff[i] stores the difference you'll make to the ith index of v[]

	for (int i = 0; i < n; i++) {
		v[i] += diff[i];
	}

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// total time : q.const + n.const + n.const ~ O(n+q)
	// total space: n+1 due to diff[] ~ O(n)

	return 0;
}