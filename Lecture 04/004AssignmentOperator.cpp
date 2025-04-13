#include<iostream>

using namespace std;

int main() {

	int x; // declaration
	x = 20; // assignment
	cout << x << endl;

	int y;
	y = 10 + 20;
	cout << y << endl;

	// by default, when you declr var. it contains garbage
	// value so it is imp. that before we use a var we
	// either read value into it or assign a value to it

	int z;
	cout << z << endl;

	int w = 2000; // initialisation = declaration + assignment
	cout << w << endl;

	return 0;
}