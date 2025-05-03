#include<iostream>

using namespace std;


int main() {

	int x = 10;
	int y = x;
	y++;
	cout << x << endl;

	int a = 20;
	int& b = a;
	b++;
	cout << a << endl;

	return 0;
}