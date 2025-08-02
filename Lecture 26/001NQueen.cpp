/*

https://leetcode.com/problems/n-queens/

N Queens Problem

The problem is to place 'n' queens on an 'n x n' chessboard, so that no two queens are attacking
each other, this means that no two queens are in the same row, the same column, or the same diagonal.

Example
	Input : N = 4
	Output:
			_ Q _ _	     _ _ Q _
	        _ _ _ Q      Q _ _ _
	        Q _ _ _      _ _ _ Q
	        _ _ Q _      _ Q _ _

	        [1, 3, 0, 2] [2, 0, 3, 1]

Constraint:
	1<=n<=10

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:

	bool isvalid(int r, int n, vector<string>& board, int j) {

		// check if you can place Qr in the jth column of row r ?

		// 1. check in the jth column if there is any previously
		// placed queen Qi where 0<=i<=r-1

		for (int i = r - 1; i >= 0; i--) {
			if (board[i][j] == 'Q') {
				// there is already a previously placed queen in the jth column
				// of the board therefore you cannot place Qr in the jth column
				// of row r
				return false;
			}
		}


		// 2. check in the right diagonal of the jth column if there is
		// any previously placed queen Qi where 0<=i<=r-1

		for (int i = r - 1, step = 1; i >= 0 and j + step < n; i--, step++) {
			if (board[i][j + step] == 'Q') {
				// you've found a previously placed queen along the right diag
				// of the jth column so you cannot place queen r in the jth col
				// of row r
				return false;
			}
		}

		// 3. check in the left diagonal of the jth column if there is
		// any previously placed queen Qi where 0<=i<=r-1

		for (int i = r - 1, step = 1; i >= 0 and j - step >= 0; i--, step++) {
			if (board[i][j - step] == 'Q') {
				// you've found a previously placed queen along the left diag
				// of the jth column so you cannot place queen r in the jth col
				// of row r
				return false;
			}
		}

		// you can place Qr in the jth column of row r

		return true;

	}

	void f(int r, int n, vector<string>& board,
	       vector<vector<string>>& allBoards) {

		// base case

		if (r == n) { // you've built a valid configuration, so track it
			allBoards.push_back(board);
			return;
		}

		// recursive case

		// f(r) = take decisions for Qr to Qn-1

		// decide for Qr

		for (int j = 0; j < n; j++) {

			if (isvalid(r, n, board, j)) {

				board[r][j] = 'Q';
				f(r + 1, n, board, allBoards);
				board[r][j] = '.';

			}

		}

	}

	vector<vector<string>> solveNQueens(int n) {

		vector<vector<string>> allBoards;

		vector<string> board;
		for (int i = 1; i <= n; i++) {
			string row(n, '.');
			board.push_back(row);
		}

		f(0, n, board, allBoards);

		return allBoards;

	}
};

int main() {

	int n;
	cin >> n;

	Solution s;

	vector<vector<string>> allBoards = s.solveNQueens(n);

	for (vector<string> board : allBoards) {
		for (string row : board) {
			cout << row << endl;
		}
		cout << endl;
	}

	return 0;
}