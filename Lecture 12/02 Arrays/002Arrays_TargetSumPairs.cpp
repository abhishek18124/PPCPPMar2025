#include<iostream>
#include<algorithm>

using namespace std;

// time : n^2.const ~ O(n^2)
// space: O(1)

int targetSumPair(int arr[], int n, int t) {

	int cnt = 0;

	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			int pairSum = arr[i] + arr[j];
			if (pairSum == t) {
				// you've found a valid pair
				cnt++;
			}
		}
	}

	return cnt;

}

// time : O(n)
// space: O(1)

int targetSumPairsOptimised(int arr[], int n, int t) {
	int cnt = 0;
	int i = 0;
	int j = n - 1;

	while (i < j) {

		int pairSum = arr[i] + arr[j];
		if (pairSum > t) {
			j--;
		} else if (pairSum < t) {
			i++;
		} else {
			// pairSum is equal to t
			cnt++;
			i++;
			j--;
		}

	}

	return cnt;
}

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr) / sizeof(int);
	int t = 60;

	cout << targetSumPair(arr, n, t) << endl;

	cout << targetSumPairsOptimised(arr, n, t) << endl;

	return 0;
}