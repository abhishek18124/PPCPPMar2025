// n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[100]; // based on constraints

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int t;
	cin >> t;

	// time : O(n)

	int i;
	bool flag = false; // assume 't' is not present in the arr[]

	for (i = 0; i < n; i++) {

		if (arr[i] == t) {

			// you've found the 1st occurrence of 't' at index i

			cout << t << " found at index " << i << endl;
			flag = true;

		}

	}

	if (flag == false) {
		cout << -1 << endl;
	}

	if (!flag) {
		cout << -1 << endl;
	}

	return 0;
}