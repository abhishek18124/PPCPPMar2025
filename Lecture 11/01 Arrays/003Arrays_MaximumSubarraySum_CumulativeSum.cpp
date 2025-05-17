// constraints : n <= 100

#include<iostream>
#include<climits>

using namespace std;

// time : n.const + n^2.const ~ O(n^2)
// space: O(n) due to psum[]

int maximumSubarraySumOptimised(int arr[], int n) {

	int psum[101]; // based on contraints
	psum[0] = 0;

	// psum[i] = sum(arr[0...i-1]) i.e.
	// psum[i] stores the sum of prefix
	// that ends at i-1th index

	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + arr[i - 1];
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << psum[i] << " ";
	// }

	// cout << endl;

	int maxSoFar = INT_MIN; // to track the maximum subarray sum

	// iterate over all subarrays

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			// find the sum of the subarray that
			// starts at the ith index and ends
			// at the jth index

			int sum = psum[j + 1] - psum[i];
			maxSoFar = max(maxSoFar, sum);

		}

	}

	return maxSoFar;

}

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySumOptimised(arr, n) << endl;

	return 0;
}