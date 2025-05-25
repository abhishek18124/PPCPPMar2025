/*

e.g.

input
9
1 0 3 2 3 1 2 0 2
3

output
0 0 1 1 2 2 2 3 3

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int k;
	cin >> k;

	vector<int> freq(k + 1, 0);

	for (int i = 0; i < n; i++) {
		// int x = v[i];
		// freq[x]++;
		freq[v[i]]++;
	}

	for (int i = 0; i <= k; i++) {
		cout << "freq(" << i << ") = " << freq[i] << endl;
	}

	for (int i = 0; i <= k; i++) {

		// print i, freq[i] times

		for (int j = 1; j <= freq[i]; j++) {
			cout << i << " ";
		}

	}

	return 0;
}