#include<iostream>

using namespace std;

int main() {

	int x = 10;
	const int& y = x;

	cout << y << endl;

	x++;

	cout << x << endl;

	cout << y << endl;

	// y++; // error since y is a const ref which means using y you can access x but you cannot modify x

	return 0;
}