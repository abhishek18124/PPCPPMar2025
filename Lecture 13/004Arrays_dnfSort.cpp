/*

e.g.

input
9
1 0 1 2 0 1 2 0 1

output
0 0 0 1 1 1 1 2 2

*/

#include<iostream>
#include<vector>

using namespace std;

// time : O(n)
// space: O(1)

void dnfSort(vector<int>& arr) { // here, we are passing by ref to avoid copy

	int n = arr.size();

	int low = 0;
	int mid = 0;
	int high = n - 1;

	while (mid <= high) {
		if (arr[mid] == 0) { // put arr[mid] to region of zeros
			swap(arr[mid], arr[low]);
			low++;
			mid++;
		} else if (arr[mid] == 1) { // put arr[mid] to region of ones
			mid++;
		} else {
			// arr[mid] == 2 // put arr[mid] to region of twos
			swap(arr[mid], arr[high]);
			high--;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

}

int main() {

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dnfSort(arr);

	return 0;

}