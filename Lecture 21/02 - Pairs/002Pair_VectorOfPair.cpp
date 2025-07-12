#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

int main() {

	vector<pair<int, int>> v;

	// v is a vector<> of pair<int, int>

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y}); // v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end());
	// sort(v.begin(), v.end(), greater<pair<int, int>>());

	// by default sorting of vector<> of pair<>
	// is done on the 1st member of the pair<>
	// in inc. order

	// in case there is a match in the values of 1st
	// member of the pair<> then comparision is done
	// on the second member

	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}

	cout << endl;

	for (pair<int, int> p : v) {
		cout << p.first << " " << p.second << endl;
	}

	cout << endl;

	// [HW] try to impl. a compartor to sort vector<> of pair<>
	// on the 2nd member

	return 0;
}