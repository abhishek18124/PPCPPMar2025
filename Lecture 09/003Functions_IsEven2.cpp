#include<iostream>

using namespace std;

bool isEven(int n) {
	return n % 2 == 0; // you can return expr from fn as expr eval. to a value
}

int main() {

	// whenever a fn call returns a value
	// you can treat that fn call like an
	// expression

	bool ans = isEven(4);

	cout << ans << endl;

	cout << isEven(5) << endl;

	if (isEven(6)) {
		cout << "even" << endl;
	} else {
		cout << "odd" << endl;
	}

	isEven(6) ? cout << "even" << endl : cout << "odd" << endl;

	return 0;
}