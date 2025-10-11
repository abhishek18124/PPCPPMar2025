#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int f(const vector<int>& arr, int n, int k, int i) {

	// base case

	if (i == n) {
		// f(n) = find the maximum sum by partitioning arr[n...n-1] = {}
		return 0;
	}

	// recursive case

	// decide the next cut

	int maxsofar = INT_MIN;
	int maxij = INT_MIN;

	for (int j = i; j <= i + k - 1 and j < n; j++) {

		// make a cut at index j
		maxij = max(maxij, arr[j]);
		maxsofar = max(maxsofar, maxij * (j - i + 1) + f(arr, n, k, j + 1));

	}

	return maxsofar;

}

// time : O(nk)
// space: O(n) due to dp[]

int fBottomUp(vector<int>& arr, int n, int k) {

	vector<int> dp(n + 1);
	dp[n] = 0; // at the nth index of dp[] we store f(n)
	for (int i = n - 1; i >= 0; i--) {
		// dp[i] = f(i) = find the maximum sum from partioning arr[i...n-1]
		// decide the next cut

		int maxsofar = INT_MIN;
		int maxij = INT_MIN;

		for (int j = i; j <= i + k - 1 and j < n; j++) {

			// make a cut at index j
			maxij = max(maxij, arr[j]);
			maxsofar = max(maxsofar, maxij * (j - i + 1) + dp[j + 1]);

		}

		dp[i] = maxsofar;

	}

	return dp[0]; // at the 0th index of dp[] we store f(0)

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {

	int n = arr.size();

	// return f(arr, n, k, 0);

	return fBottomUp(arr, n, k);

}

int main() {

	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;

	cout << maxSumAfterPartitioning(arr, k) << endl;

	return 0;
}