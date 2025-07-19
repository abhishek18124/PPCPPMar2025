// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int arr[], int s, int e) {

	// partition arr[s..e] around the pivot

	int low = s; // points to the index where we'll keep next element < pivot
	int mid = s; // points to the index under consideration

	int pivot = arr[e];

	while (mid < e) {

		if (arr[mid] < pivot) {
			// put arr[mid] in left paritition
			swap(arr[low], arr[mid]);
			low++;
			mid++;
		} else {
			// put arr[mid] in right partition
			mid++;
		}

	}

	// put the pivot i.e. arr[e] b/w the left and right partition

	swap(arr[e], arr[low]);

	return low; // pivot index

}

void quickSort(int arr[], int s, int e) {

	// base case

	if (s == e) { // optional base case
		return;
	}

	if (s > e) { // mandatory base case
		return;
	}

	// recursive case

	// f(s, e) = sort arr[s...e] using quickSort algorithm

	// 1. partition the arr[s...e] around the pivot i.e. arr[e]

	int pidx = partition(arr, s, e);

	// 2. recursively sort the left and the right parition i.e.
	// arr[s...pidx-1] and arr[pidx+1...e]

	quickSort(arr, s, pidx - 1);
	quickSort(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}