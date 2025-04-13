#include<iostream>
#include<cmath>

using namespace std;

#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 2;

	while (i <= sqrt(n)) {

		if (n % i == 0) {

			// you've found a factor n in the range [2, n-1]

			cout << "not prime" << endl;
			break;

		}

		i = i + 1;

	}

	if (i > sqrt(n)) { // we came outside the loop due to loop condition
		// being false which only happens for a prime no.
		cout << "prime" << endl;
	}

	return 0;
}