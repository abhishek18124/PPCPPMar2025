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

	// 2. sorting a vector in the decreasing order

	// sort(v.rbegin(), v.rend());

	sort(v.begin(), v.end(), greater<int>()); // greater<int>() is a function object / functor

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}