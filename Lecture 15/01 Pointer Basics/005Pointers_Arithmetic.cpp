#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int* xptr = &x;

	cout << "xptr = " << xptr << endl; // 100

	// xptr++;
	xptr = xptr + 3;

	cout << "xptr = " << xptr << endl; // 104

	return 0;
}