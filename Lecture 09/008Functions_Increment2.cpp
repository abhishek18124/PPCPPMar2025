#include<iostream>

using namespace std;

void incr(int& ref) { // here a is passed by reference i.e. 'ref' is like a new name for 'a'
	ref++;
}

int main() {

	int a = 10;

	incr(a);

	cout << a << endl;

	return 0;
}