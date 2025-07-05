#include<iostream>

using namespace std;

// time : O(mn)

bool isPresent(int mat[][3], int m, int n, int t) {

	for (int i = 0; i < m; i++) {

		// search for the 't' in the ith row

		for (int j = 0; j < n; j++) {

			if (mat[i][j] == t) {

				// you've found the 't' in the (i,j)th cell
				return true;

			}

		}

	}

	// 't' is not present in the mat[][]
	return false;

}

int main() {

	int mat[][3]  = {
		{50, 80, 20},
		{90, 10, 70},
		{60, 30, 40}
	};

	int m = 3;
	int n = 3;

	int t = 100;

	isPresent(mat, m, n, t) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}