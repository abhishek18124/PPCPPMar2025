#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {

		// f(x, 0) = find pow(x, 0) i.e. mul. x, 0 times

		return 1;

	}

	// recursive case

	// f(x, y) = find pow(x, y) i.e. mul. x, y times

	// 1. ask your friend to find pow(x, y-1) i.e. mul. x, y-1 times

	int A = f(x, y - 1);

	return x * A;

}

int main() {

	int x = 2;
	int y = 5;

	cout << f(x, y) << endl;

	return 0;

}