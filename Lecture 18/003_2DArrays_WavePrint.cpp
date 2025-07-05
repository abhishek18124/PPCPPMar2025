#include<iostream>

using namespace std;

// time : O(mn)

void wavePrint(int mat[][10], int m, int n) {

	for (int j = 0; j < n; j++) {

		// print values in the jth column

		if (j % 2 == 0) {

			// jth column is even

			// iterate over rows from top to bottom

			for (int i = 0; i < m; i++) {

				cout << mat[i][j] << " ";

			}

		} else {

			// jth column is odd

			// iterate over row from bottom to top

			for (int i = m - 1; i >= 0; i--) {

				cout << mat[i][j] << " ";

			}

		}

	}

}

int main() {

	int mat[][10] = {
		{10, 20, 30},
		{40, 50, 60},
		{70, 80, 90}
	};

	int m = 3;
	int n = 3;

	wavePrint(mat, m, n);

	return 0;
}