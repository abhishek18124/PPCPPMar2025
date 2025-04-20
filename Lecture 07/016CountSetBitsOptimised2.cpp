#include<iostream>

using namespace std;

int main() {

	int n = 8;
	int cnt = 0; // to track the no. of set bits in 'n'

	while (n > 0) { // logn iterations

		int rightmostbit = n & 1;
		if (rightmostbit == 1) {
			cnt++;
		}
		n = n >> 1;

	}

	cout << cnt << endl;

	return 0;
}