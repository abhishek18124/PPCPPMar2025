#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	cout << (void*)&greet << endl;
	cout << (void*)&add << endl;
	cout << (void*)&ascending << endl;

	// to access address of a fn, using & is optional

	cout << (void*)greet << endl;
	cout << (void*)add << endl;
	cout << (void*)ascending << endl;

	void (*gptr)() = &greet;
	int (*aptr)(int, int) = &add;
	bool (*ascptr)(int, int) = &ascending;

	cout << (void*)gptr << endl;
	cout << (void*)aptr << endl;
	cout << (void*)ascptr << endl;

	// while calling a fn using a fn ptr, the use of dereference operator i.e. * is optional

	(*gptr)();
	greet();
	gptr();
	(*greet)();

	cout << (*aptr)(5, 7) << endl;
	cout << add(5, 7) << endl;
	cout << aptr(5, 7) << endl;
	cout << (*add)(5, 7) << endl;

	cout << (*ascptr)(3, 2) << endl;
	cout << ascending(3, 2) << endl;
	cout << ascptr(3, 2) << endl;
	cout << (*ascending)(3, 2) << endl;

	return 0;
}