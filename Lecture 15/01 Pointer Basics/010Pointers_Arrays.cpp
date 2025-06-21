#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	cout << arr << " " << &arr[0] << endl;

	// in c++, name of the array is like an pointer to the 1st element of the array i.e. the element at the 0th index

	cout << (arr + 1) << " " << &arr[1] << endl;
	cout << (arr + 2) << " " << &arr[2] << endl;
	cout << (arr + 3) << " " << &arr[3] << endl;
	cout << (arr + 4) << " " << &arr[4] << endl << endl;

	for (int i = 0; i < 5; i++) {
		cout << (arr + i) << " " << &arr[i] << " " << *(arr + i) << " " << arr[i] << endl;;
	}

	return 0;
}