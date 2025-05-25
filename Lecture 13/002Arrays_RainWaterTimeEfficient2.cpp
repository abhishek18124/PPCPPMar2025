#include<iostream>
#include<vector>

using namespace std;

// time : 2n steps and each step is const therefore ~ O(n)
// space: n due r[] ~ O(n)

int trap(vector<int>& h) {

	int n = h.size();

	vector<int> r(n);
	r[n - 1] = h[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;
	int maxsofar = 0; // li

	for (int i = 0; i < n; i++) {

		// find out the water trapped on top of the ith building

		maxsofar = max(maxsofar, h[i]); // track max(h[0..i])
		int wi = min(maxsofar, r[i]) - h[i];
		total += wi;

	}

	return total;

}

int main() {

	vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	cout << trap(h) << endl;

	return 0;
}