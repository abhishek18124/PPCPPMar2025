#include<iostream>

using namespace std;

int main() {

	int arr[5];
	cout << sizeof(arr) << endl;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	cout << arr[0] << " "
	     << arr[1] << " "
	     << arr[2] << " "
	     << arr[3] << " "
	     << arr[4] << endl;

	int n = sizeof(arr) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	for (int i = 0; i <= n - 1; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	char str[10];
	cout << sizeof(str) << endl;

	double brr[20];
	cout << sizeof(brr) << endl;

	return 0;
}