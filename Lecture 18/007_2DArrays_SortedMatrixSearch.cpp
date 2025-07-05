#include<iostream>
#include<algorithm>

using namespace std;

// time : O(mlogn)

bool isPresent(int mat[][3], int m, int n, int t) {

	for (int i = 0; i < m; i++) {

		// apply binary search to search for 't' in the ith row

		if (binary_search(mat[i], mat[i] + n, t)) { // [start, end)

			// you've found the target in the ith row

			return true;

		}

	}

	// target is not found
	return false;

}

int main() {

	int mat[][3] = {
		{40, 50, 60},
		{10, 20, 30},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	int t = 1000;

	isPresent(mat, m, n, t) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}