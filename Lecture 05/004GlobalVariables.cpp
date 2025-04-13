#include<iostream>

using namespace std;

int x = 100; // global variable

int main() {

	cout << x << endl; // 100

	int x = 10;

	cout << x << endl; // 10 // local x is shadowing global x

	cout << ::x << endl; // we can scope resolution operator to access global x and overcome variable shadowing

	return 0;
}