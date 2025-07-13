#include<iostream>

using namespace std;

void f(int n) {

	// base case

	if (n == 0) {

		// f(0) = print nos. from 1 to 0 in inc. order

		return; // mandatory

	}

	// recursive case

	// f(n) = print nos. from 1 to n in inc. order

	// 1. ask your friend to print nos. from 1 to n-1 in inc. order

	f(n - 1);

	cout << n << " ";

	return; // optional

}

int main() {

	int n = 5;

	f(n);

	return 0;

}