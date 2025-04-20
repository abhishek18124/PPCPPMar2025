#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 4;

	if ((n >> k) & 1) { // ((n >> k) & 1) == 1
		cout << "bit " << k << " of " << n << " is set" << endl;
	} else {
		cout << "bit " << k << " of " << n << " is not set" << endl;
	}

	return 0;
}