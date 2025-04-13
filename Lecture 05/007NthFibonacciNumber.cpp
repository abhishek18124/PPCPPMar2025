#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 || n == 1) {
		cout << n << endl;
	} else {

		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.


		int i = 2;

		while (i <= n) { // to find the nth fib. no. run this loop n-1 times
			int c = a + b;
			a = b;
			b = c;
			i = i + 1;
		}

		cout << b << endl; // whatever is in c is eventually assigned to b

	}

	return 0;
}