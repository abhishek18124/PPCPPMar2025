#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int* ptr1 = &x; // ptr1 is a pointer to int
	const int* ptr2 = &x;
	int * const ptr3 = &x;

	(*ptr1)++; // works
	// (*ptr2)++; // error
	(*ptr3)++; // works

	ptr1++; // works
	ptr2++; // works
	// ptr3++; // does not work since ptr3 is a const pointer

	return 0;
}