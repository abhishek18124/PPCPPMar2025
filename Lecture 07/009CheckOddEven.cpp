#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n & 1) { // writing (n&1) == 1 is redundant
		cout << "odd" << endl;
	} else {
		cout << "even" << endl;
	}

	return 0;
}