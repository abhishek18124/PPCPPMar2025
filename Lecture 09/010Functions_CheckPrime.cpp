#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {

	int rn = sqrt(n);

	for (int i = 2; i <= rn; i++) {
		if (n % i == 0) {
			// you've found a factor of n in the range [2, rn]
			// therefore n is not prime no.
			return false;
		}
	}

	// you did not find any factor of n in the range [2, rn]
	// therefore n is a prime no.

	return true;
}

int main() {

	int n;
	cin >> n;

	isPrime(n) ? cout << n << " is prime" << endl : cout << n << " is not prime" << endl;

	return 0;
}