// https://leetcode.com/problems/max-area-of-island/description/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:

	vector<int> dx = {0, 0, -1, 1};
	vector<int> dy = {1, -1, 0, 0};

	int dfs(int i, int j,
	        const vector<vector<int>>& grid,
	        vector <vector<bool>>& vis,
	        int m, int n) {

		// find the size of the component which contains
		// the node corr. to the i,jth cell

		vis[i][j] = true;

		int cnt = 1; // to track the size of the component

		for (int k = 0; k < 4; k++) {

			int nx = i + dx[k];
			int ny = j + dy[k];

			if (nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] == 1 and !vis[nx][ny]) {
				cnt += dfs(nx, ny, grid, vis, m, n);
			}

		}

		return cnt;

	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {

		int m = grid.size();
		int n = grid[0].size();

		vector<vector<bool>> vis(m, vector<bool>(n, false));
		int maxsofar = 0; // to track the area of the largest island // don't use INT_MIN, what if grid contains only zero

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1 and !vis[i][j]) {
					// (i, j)th cell corresponds to a node in the graph
					// which is still not visited so make the node corr.
					// to the (i, j)th cell as src and find the size of
					// its component using dfs(...)
					maxsofar = max(maxsofar, dfs(i, j, grid, vis, m, n));
				}
			}
		}

		return maxsofar;

	}
};

int main() {

	vector<vector<int>> grid = {
		{1, 0, 0, 1, 0},
		{1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0}
	};

	Solution s;
	cout << s.maxAreaOfIsland(grid) << endl;

	return 0;

}