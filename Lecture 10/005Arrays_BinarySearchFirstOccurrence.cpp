#include<iostream>

using namespace std;

// time : O(logn)

int lowerBound(int arr[], int n, int t) { // finds the index of 1st occcurrence of 't' in arr[]

	int s = 0;
	int e = n - 1;

	int ans = -1; // to track the index of 1st occurrence of 't' in arr[]

	while (s <= e) {

		// int m = (s + e) / 2;

		int m = s + (e - s) / 2;

		if (arr[m] == t) {
			ans = m;
			e = m - 1;
		} else if (t > arr[m]) {
			s = m + 1;
		} else {
			// t < arr[m]
			e = m - 1;
		}

	}

	return ans;

}

int main() {

	int arr[] = {10, 20, 20, 20, 20, 20, 30};
	int n = sizeof(arr) / sizeof(int);

	int t = 20;

	cout << lowerBound(arr, n, t) << endl;

	return 0;
}