#include<iostream>

using namespace std;

void insertionSort(int arr[], int n) {

	for (int i = 1; i <= n - 1; i++) {

		int key = arr[i];

		// in the ith pass, insert the key to its correct position
		// in the sorted part of the array

		int j = i - 1;

		while (j >= 0 and key < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;

	}

}

int main() {

	int arr[] = {50, 40, 10, 30, 20};
	int n = sizeof(arr) / sizeof(int);

	insertionSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}