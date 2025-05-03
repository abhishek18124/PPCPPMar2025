#include<iostream>

using namespace std;

void incr(int a) { // here a is passed by value
	a++;
}

int main() {

	int a = 10;

	incr(a);

	cout << a << endl;

	return 0;
}