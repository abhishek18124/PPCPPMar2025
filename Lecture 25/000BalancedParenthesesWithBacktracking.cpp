// n <= 8

#include<iostream>

using namespace std;

void f(int n, string& out, int oc, int cc) {

	// base case

	if (out.size() == 2 * n) { // oc == n and cc = n
		cout << out << endl;
		return;
	}

	// recursive case

	// f(i, oc, cc) = take decisions for the remaining
	// positions i to 2n-1 s.t. oc '(' and cc ')' are
	// already used

	// decide for the ith position

	// option 1 : use '('

	if (oc < n) {
		out.push_back('(');
		f(n, out, oc + 1, cc);
		out.pop_back(); // backtracking
	}

	// option 2 : use ')'
	if (cc < oc) {
		out.push_back(')');
		f(n, out, oc, cc + 1);
		out.pop_back(); // backtracking
	}

}

int main() {

	int n = 3;

	string out; // based on constraints

	f(n, out, 0, 0);

	return 0;
}