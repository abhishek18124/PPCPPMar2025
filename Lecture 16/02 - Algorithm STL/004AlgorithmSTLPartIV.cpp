#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	int key = 30;

	// 1. searching for a key in a sequence using find()

	auto it = find(arr, arr + n, key);

	if (it != arr + n) {

		cout << key << " found at index = " << it - arr << endl;

	}

	key = 100;

	it = find(arr, arr + n, key);

	cout << it << endl;
	cout << (arr + n) << endl;

	if (it == arr + n) {
		cout << key << " is not present" << endl;
	}

	// 2. counting the occurrences of a key in a sequence using count()

	key = 30;

	cout << "count(" << key << ") = " << count(arr, arr + n, key) << endl;

	key = 100;

	cout << "count(" << key << ") = " << count(arr, arr + n, key) << endl;

	return 0;
}
