#include<iostream>

using namespace std;

void myswap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int main() {

	int a = 10;
	int b = 20;

	cout << a << " " << b << endl;

	myswap(a, b);

	cout << a << " " << b << endl;

	return 0;
}