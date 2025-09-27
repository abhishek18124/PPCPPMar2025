/*

Given a number n, count the minimum steps to reduce n to 1
such that at each step you may

	reduce n to n/2 if n is divisible by 2
	or reduce n to n/3 if n is divisible by 3
	or reduce n to n-1 by decrementing n by 1

Example :
	Input : n = 10
	Output : 3

	Input : 6
	Output : 2

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int cntr1 = 0;

// time : O(3^n)
// space: O(n) due to fn call stack

int f(int n) {

	cntr1++;

	// base case

	if (n == 1) {

		// f(1) = find min. no. of steps required to reduce 1 to 1

		return 0;

	}

	// recursive case

	// f(n) = find min. no. of steps requried to reduce n to 1

	// decide the next option

	// option 1 : reduce n to n-1

	int op1 = f(n - 1);

	// option 2 : reduce n to n/2 if n%2 is zero

	int op2 = INT_MAX;
	if (n % 2 == 0) {
		op2 = f(n / 2);
	}

	// option 3 : reduce n to n/3 if n%3 is zero

	int op3 = INT_MAX;
	if (n % 3 == 0) {
		op3 = f(n / 3);
	}

	return 1 + min(op1, min(op2, op3));

}

int cntr2 = 0;

// time : O(n)
// space: O(n) due to fn call stack + dp[]

int fTopdown(int n, vector<int>& dp) {

	cntr2++;

	// lookup

	if (dp[n] != -1) {
		// you've solved f(n) previously, so reuse the result
		return dp[n];
	}

	// base case

	if (n == 1) {

		// f(1) = find min. no. of steps required to reduce 1 to 1

		return dp[n] = 0; // saving in base case is optional

	}

	// recursive case

	// f(n) = find min. no. of steps requried to reduce n to 1

	// decide the next option

	// option 1 : reduce n to n-1

	int op1 = fTopdown(n - 1, dp);

	// option 2 : reduce n to n/2 if n%2 is zero

	int op2 = INT_MAX;
	if (n % 2 == 0) {
		op2 = fTopdown(n / 2, dp);
	}

	// option 3 : reduce n to n/3 if n%3 is zero

	int op3 = INT_MAX;
	if (n % 3 == 0) {
		op3 = fTopdown(n / 3, dp);
	}

	return dp[n] = 1 + min(op1, min(op2, op3));

}

// time : O(n)
// space: O(n) due to dp[]

int fBottomUp(int n) {

	vector<int> dp(n + 1); // 0th index is not used
	dp[1] = 0; // at the 1st index of dp[] we store f(1)

	for (int i = 2; i <= n; i++) {

		// dp[i] = f(i) = find min. no. of steps required to reduce i to 1

		// decide the next option

		// option 1 : reduce i to i-1

		int op1 = dp[i - 1];

		// option 2 : reduce i to i/2

		int op2 = INT_MAX;
		if (i % 2 == 0) {
			op2 = dp[i / 2];
		}

		// option 3 : reduce i to i/3

		int op3 = INT_MAX;
		if (i % 3 == 0) {
			op3 = dp[i / 3];
		}

		dp[i] = 1 + min(op1, min(op2, op3));

	}

	return dp[n]; // at the nth index of dp[] we store f(n)

}

int main() {

	int n = 50;

	cout << f(n) << endl;

	vector<int> dp(n + 1, -1); // 0th index is not used

	cout << fTopdown(n, dp) << endl;

	cout << cntr1 << endl;

	cout << cntr2 << endl;

	cout << fBottomUp(n) << endl;

	return 0;
}