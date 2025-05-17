#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	// 1. creating a vector using initialiser list

	vector<int> v = {1, 0, 2, 4, 3};

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// 2. reversing a vector

	reverse(v.begin(), v.end()); // [first, last)

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	// 3. sorting a vector in the increasing order

	sort(v.begin(), v.end()); // by default sorting is done in inc. order

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	vector<int> a = {10, 40, 30, 20, 50};
	reverse(a.begin() + 1, a.begin() + 4);
	for (int x : a) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}