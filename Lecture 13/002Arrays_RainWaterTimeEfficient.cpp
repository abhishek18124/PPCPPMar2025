#include<iostream>
#include<vector>

using namespace std;

// time : 3n steps and each step is const therefore ~ O(n)
// space: 2n due l[], r[] ~ O(n)

int trap(vector<int>& h) {

	int n = h.size();

	vector<int> l(n);
	l[0] = h[0];

	for (int i = 1; i < n; i++) {
		l[i] = max(l[i - 1], h[i]);
	}

	vector<int> r(n);
	r[n - 1] = h[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(r[i + 1], h[i]);
	}

	int total = 0;

	for (int i = 0; i < n; i++) {

		// find out the water trapped on top of the ith building

		int wi = min(l[i], r[i]) - h[i];
		total += wi;

	}

	return total;

}

int main() {

	vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	cout << trap(h) << endl;

	return 0;
}