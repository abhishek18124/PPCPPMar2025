#include<iostream>

using namespace std;

int main() {

	int n, p;
	cin >> n >> p;

	double ans;

	int s = 0;
	int e = n;

	while (s <= e) { // log(e-s) = log(n-0) = logn

		int m = s + (e - s) / 2;

		if (m * m <= n) {

			ans = m;
			s = m + 1;

		} else {

			e = m - 1;

		}

	}

	double inc = 0.1;

	for (int i = 1; i <= p; i++) { // p.10.const
		while (ans * ans <= n) {
			ans = ans + inc;
		}

		ans = ans - inc;
		inc = inc / 10;
	}


	cout << ans << endl;

	return 0;
}