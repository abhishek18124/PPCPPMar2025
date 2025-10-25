// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<climits>
#include<queue>

using namespace std;

// appr1 - brute-force
// time : O(m^2.n^2)

vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> distMat(m, vector<int>(n, INT_MAX));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// find the manhattan dist b/w (i, j)th cell and all the other cells
				for (int ii = 0; ii < m; ii++) {
					for (int jj = 0; jj < n; jj++) {
						// manhattan dist. b/w (i,j)th and (ii,jj)th cell = |ii-i| + |jj-j|
						distMat[ii][jj] = min(distMat[ii][jj],
						                      abs(ii - i) + abs(jj - j));
					}
				}
			}
		}
	}

	return distMat;

}

// appr2 - multi-source bfs
// time : O(mn)
// space : mn due to distMap + mn due to queue<> (when each cell is zero) ~ O(mn)

vector<vector<int>> updateMatrixOptimised(const vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> distMat(m, vector<int>(n, INT_MAX)); // init helps us to also check if a node is visited or not
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// (i, j)th cell corresponds to a source node
				q.push({i, j});
				distMat[i][j] = 0;
			}
		}
	}

	int dx[] = {0, 0, -1, 1};
	int dy[] = {1, -1, 0, 0};

	while (!q.empty()) {

		// pair<int, int> p = q.front();
		// q.pop();

		// int cur_i = p.first;
		// int cur_j = p.second;

		auto [cur_i, cur_j] = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = cur_i + dx[k];
			int ny = cur_j + dy[k];
			if (nx >= 0 and nx < m and ny >= 0 and ny < n and distMat[nx][ny] == INT_MAX) {
				// visit the node corr. to the (nx, ny)th cell
				q.push({nx, ny});
				distMat[nx][ny] = distMat[cur_i][cur_j] + 1;
			}
		}

	}

	return distMat;

}

int main() {

	vector<vector<int>> mat = {
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	// vector<vector<int>> distMat = updateMatrix(mat);

	vector<vector<int>> distMat = updateMatrixOptimised(mat);

	int m = distMat.size();
	int n = distMat[0].size();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << distMat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;

}