#include<iostream>

using namespace std;

int computeSum(int arr[], int n) {

	// cout << sizeof(arr) << endl;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	return sum;
}

int main() {

	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);

	// cout << sizeof(arr) << endl;

	cout << computeSum(arr, n) << endl;

	return 0;
}