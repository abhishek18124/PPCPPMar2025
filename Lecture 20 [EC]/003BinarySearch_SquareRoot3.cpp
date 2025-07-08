#include<iostream>
#include<iomanip>

using namespace std;

int main() {

	int n, p;
	cin >> n >> p;

	double ans;

	double s = 0;
	double e = n;

	double error = 1e-7; // 10^-6
	int numIterations = 80;

	for (int i = 1; i <= numIterations; i++) {

		double m = s + (e - s) / 2;

		if (m * m <= n) {

			ans = m;
			s = m + error;

		} else {

			e = m - error;

		}

	}

	cout << setprecision(p) << fixed << ans << endl;


	return 0;
}