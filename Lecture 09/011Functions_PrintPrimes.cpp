#include<iostream>
#include<cmath>

using namespace std;

// 3 adv. of using functions

// readability
// modularity
// reusability

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

void printPrimes(int m) {
	for (int n = 2; n <= m; n++) {
		if (isPrime(n)) {
			cout << n << " ";
		}

	}
}

int main() {

	int m;
	cin >> m;

	printPrimes(m);

	return 0;
}