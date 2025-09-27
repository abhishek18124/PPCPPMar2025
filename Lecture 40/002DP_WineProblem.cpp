/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year
you can sell the first or the last wine in the row. However, the price of wines increases
over time.

Let the initial prices of the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit
from the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : prices[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>
#define vvvi vector <vector<vector<int>>>

using namespace std;

int f(const vector<int>& p, int i, int j, int y) {

	// base case

	if (i == j) { // y == p.size()
		return p[i] * y; // p[j] * y
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell ith bottle

	// option 2 : sell jth bottle

	return max(y * p[i] + f(p, i + 1, j, y + 1),
	           y * p[j] + f(p, i, j - 1, y + 1));

}

int fTopdown(const vector<int>& p, int i, int j, int y, vvvi& dp) {

	// lookup
	if (dp[i][j][y] != -1) {
		return dp[i][j][y];
	}

	// base case

	if (i == j) { // y == p.size()
		return dp[i][j][y] = p[i] * y; // p[j] * y
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell ith bottle

	// option 2 : sell jth bottle

	return dp[i][j][y] = max(y * p[i] + fTopdown(p, i + 1, j, y + 1, dp),
	                         y * p[j] + fTopdown(p, i, j - 1, y + 1, dp));

}

int fParameterOptimised(const vector<int>& p, int i, int j) {

	int y = p.size() - j + i;

	// base case

	if (i == j) { // y == p.size()
		return p[i] * y; // p[j] * y
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell ith bottle

	// option 2 : sell jth bottle

	return max(y * p[i] + fParameterOptimised(p, i + 1, j),
	           y * p[j] + fParameterOptimised(p, i, j - 1));

}

int fParameterOptimisedTopdown(const vector<int>& p, int i, int j, vector<vector<int>>& dp) {

	int y = p.size() - j + i;

	// lookup
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// base case

	if (i == j) { // y == p.size()
		return dp[i][j] = p[i] * y; // p[j] * y
	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell ith bottle

	// option 2 : sell jth bottle

	return dp[i][j] = max(y * p[i] + fParameterOptimisedTopdown(p, i + 1, j, dp),
	                      y * p[j] + fParameterOptimisedTopdown(p, i, j - 1, dp));

}

// time : O(n^2)
// space: O(n^2), can be optimised to O(n)

int fBottomUp(const vector<int>& p, int n) {
	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		// int j = i;
		// int y = n;
		// dp[i][j] = p[i] * y;
		dp[i][i] = p[i] * n;
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			// dp[i][j] = f(i, j)
			int y = n - j + i;
			dp[i][j] = max(y * p[i] + dp[i + 1][j],
			               y * p[j] + dp[i][j - 1]);
		}
	}

	return dp[0][n - 1]; // at the 0,n-1th index we store f(0, n-1)
}

int main() {

	vector<int> p = {2, 3, 5, 1, 4};
	int n = p.size();

	cout << f(p, 0, n - 1, 1) << endl;

	vvvi dp(n,
	        vector<vector<int> > (n,
	                              vector<int>(n + 1, -1)));

	cout << fTopdown(p, 0, n - 1, 1, dp) << endl;

	cout << fParameterOptimised(p, 0, n - 1) << endl;

	vector<vector<int>> dp2(n, vector<int>(n, -1));

	cout << fParameterOptimisedTopdown(p, 0, n - 1, dp2) << endl;

	cout << fBottomUp(p, n) << endl;

	return 0;
}