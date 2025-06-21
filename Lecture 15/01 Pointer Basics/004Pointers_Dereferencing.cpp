#include<iostream>

using namespace std;

int main() {

	int x = 10;
	int *xptr = &x;

	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "xptr = " << xptr << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << endl;
	cout << "*xptr = " << *xptr << endl << endl;

	char ch = 'A';
	char* chptr = &ch;
	cout << "*chptr = " << *chptr << endl << endl;

	double y = 3.14;
	double* yptr = &y;
	cout << "*yptr = " << *yptr << endl;

	return 0;
}