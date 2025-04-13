#include<iostream>

using namespace std;

int main() {

	int a = 10;
	int b = 5;

	cout << "a > b = " << (a > b) << endl; // 1
	cout << "a >= b = " << (a >= b) << endl; // 1
	cout << "a < b = " << (a < b) << endl; // 0
	cout << "a <= b = " << (a <= b) << endl; // 0
	cout << "a == b = " << (a == b) << endl; // 0
	cout << "a != b = " << (a != b) << endl; // 1

	return 0;
}