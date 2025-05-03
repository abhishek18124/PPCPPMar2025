#include<iostream>

using namespace std;

int multiply(int a, int b) {
	int c = a * b;
	return c;
}

int main() {

	int a = 2;
	int b = 3;

	cout << multiply(a, b) << endl;

	return 0;
}