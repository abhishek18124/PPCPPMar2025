#include<iostream>

using namespace std;

int main() {

	int a = 25;
	int b = 19;

	cout << "a&b = " << (a & b) << endl;
	cout << "a|b = " << (a | b) << endl;
	cout << "a^b = " << (a ^ b) << endl;
	cout << "~a  = " << (~a)  << endl;

	int c = 0;
	cout << "~c = " << (~c) << endl;

	return 0;
}