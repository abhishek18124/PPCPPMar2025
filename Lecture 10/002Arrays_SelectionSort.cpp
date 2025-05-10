#include<iostream>

using namespace std;

void selectionSort(int arr[], int n) {

	for (int i = 0; i <= n - 2; i++) {

		// in the ith pass, place the smallest element in the
		// unsorted part of the arr[] to its correct position
		// i.e. ith index

		int minIdx = i; // at the start of the ith pass, assume value at the ith index is the smallest

		for (int j = i + 1; j <= n - 1; j++) { // to verify the assumption, iterate over remaining elements

			if (arr[j] < arr[minIdx]) { // you've found an element less than value at minIdx

				minIdx = j; // therefore update minIdx with the index of that element

			}

		}

		swap(arr[minIdx], arr[i]);

	}

}

int main() {

	int arr[] = {50, 40, 30, 20, 10};
	int n = sizeof(arr) / sizeof(int);

	selectionSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}