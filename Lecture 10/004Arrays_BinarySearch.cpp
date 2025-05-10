#include<iostream>

using namespace std;

int binarySearch(int arr[], int n, int t) {

	int s = 0; // lower bound of the search space
	int e = n - 1; // upper bound of the search space

	while (s <= e) {

		// int m = (s + e) / 2;

		int m = s + (e - s) / 2;

		if (arr[m] == t) {

			return m; // you've found the target at index m

		} else if (t > arr[m]) {

			s = m + 1; // go towards the right of the midPoint i.e. reduce the search space from [s, e] to [m+1, e]

		} else {

			// t < arr[m]

			e = m - 1; // go towards the left of the midPoint i.e. reduce the search space from [s, e] to [s, m-1]

		}
	}

	return -1; // target is not present in the arr[]

}

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	cout << binarySearch(arr, n, t) << endl;

	return 0;
}