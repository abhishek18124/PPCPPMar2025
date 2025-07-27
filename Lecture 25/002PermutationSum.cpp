#include<iostream>
#include<vector>

using namespace std;

void f(const vector<int>& c, int t, vector<int>& perm) {

	// base case

	if (t == 0) { // you've built a valid permuation, so print it and return
		for (int el : perm) {
			cout << el << " ";
		}
		cout << endl;
		return;
	}

	// recursive case

	// decide the next element for perm[]

	for (int j = 0; j < c.size(); j++) {
		// is c[j] a valid option ? can we take it as the next element ?
		if (c[j] <= t) { // take c[j] as the next element
			perm.push_back(c[j]);
			f(c, t - c[j], perm);
			perm.pop_back(); // backtracking
		}
	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> perm; // to track a single permuation


	f(c, t, perm);

	return 0;
}