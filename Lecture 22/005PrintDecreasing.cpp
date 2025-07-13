#include<iostream>

using namespace std;

void f(int n) {

	// base case

	if (n == 0) {

		// f(0) = print nos. from 0 to 1 in dec. order

		return; // mandatory

	}

	// recursive case

	// f(n) = print nos. from n to 1 in dec. order

	cout << n << " ";

	// 1. ask your friend to print nos. from n-1 to 1 in dec. order

	f(n - 1);

	return; // optional

}

int main() {

	int n = 5;

	f(n);

	return 0;

}