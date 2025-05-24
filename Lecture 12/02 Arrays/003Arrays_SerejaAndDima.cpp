#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int serejaScore = 0;
	int dimaScore = 0;

	int i = 0;
	int j = n - 1;

	bool isSerejasTurn = true;

	while (i <= j) {

		if (isSerejasTurn) {

			if (v[i] > v[j]) {
				// sereja will pick the ith card
				serejaScore += v[i];
				i++;
			} else {
				// sereja will pick the jth card
				serejaScore += v[j];
				j--;
			}

			isSerejasTurn = false;

		} else {

			if (v[i] > v[j]) {
				// dima will pick the ith card
				dimaScore += v[i];
				i++;
			} else {
				// dima will pick the jth card
				dimaScore += v[j];
				j--;
			}

			isSerejasTurn = true;

		}

	}

	cout << serejaScore << " " << dimaScore << endl;

	return 0;
}