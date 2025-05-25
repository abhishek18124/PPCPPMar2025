#include<iostream>
#include<vector>

using namespace std;

int trap(vector<int>& h) {

	int n = h.size();

	int total = 0;

	for (int i = 0; i < n; i++) {

		// find out the water trapped on top of the ith building

		int li = h[i];
		for (int j = i - 1; j >= 0; j--) {
			// if (h[j] > li) {
			// 	li = h[j];
			// }

			li = max(li, h[j]);
		}

		int ri = h[i];
		for (int j = i + 1; j < n; j++) {
			// if (h[j] > ri) {
			// 	ri = h[j];
			// }

			ri = max(ri, h[j]);
		}

		int wi = min(li, ri) - h[i];
		total += wi;

	}

	return total;

}

int main() {

	vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	// cout << trap(h) << endl;

	return 0;
}