/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> count the number of paths that exist between src and dst

such at each step the rat can only move in the right or down direction.

Constraint

 1 <= m, n < 10

Example
	Input :

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}

	Output : 3

*/

#include<iostream>

using namespace std;

int f(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) { // you've gone outside the maze
		return 0;
	}

	if (maze[i][j] == 'X') { // you've reached a blocked cell
		return 0;
	}

	if (i == m - 1 and j == n - 1) { // you've reached the destn
		return 1;
	}

	// recursive case

	// f(i, j) = count no. of paths from (i, j)th cell to (m-1, n-1)th cell

	// decide the next step

	// option 1 : move right, and now ask your friend find out no. of paths
	// from i,j+1 to m-1,n-1

	int x = f(maze, m, n, i, j + 1);

	// option 2 : move down, and now ask your friend to find out no. of paths
	// from i+1,j to m-1,n-1

	int y = f(maze, m, n, i + 1, j);

	return x + y;

	// return f(maze, m, n, i, j + 1) + f(maze, m, n, i + 1, j);

}

int main() {

	char maze[][10] = {
		"0000",
		"00X0",
		"000X",
		"0X00"
	};

	int m = 4;
	int n = 4;

	cout << f(maze, m, n, 0, 0) << endl;

	return 0;
}