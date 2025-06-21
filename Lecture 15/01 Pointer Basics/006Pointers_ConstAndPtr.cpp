#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int*ptr1 = &x; // ptr1 is a pointer to int

	const int*ptr2 = &x; // ptr to a pointer to a const-int

	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

	cout << ptr1 << endl;
	cout << ptr2 << endl;

	// ptr1++;
	// ptr2++;

	// cout << ptr1 << endl;
	// cout << ptr2 << endl;

	(*ptr1)++;

	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

	// (*ptr2)++; // error since ptr2 is a pointer to const-int

	return 0;
}