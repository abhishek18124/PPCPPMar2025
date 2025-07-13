#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {
		// f(x, 0) = add x, 0 times i.e. multiply x and 0
		return 0;
	}

	// recursive case

	// f(x, y) = add x, y times

	// 1. ask your friend to add x, y-1 times i.e. multiply x and y-1

	int A = f(x, y - 1);

	return x + A;

}

int main() {

	int x = 3;
	int y = 4;

	cout << f(x, y) << endl;

	return 0;

}