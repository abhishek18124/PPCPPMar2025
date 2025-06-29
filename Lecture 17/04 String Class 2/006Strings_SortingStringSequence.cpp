#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {

	vector<string> v;

	v.push_back("rohan");
	v.push_back("agrima");
	v.push_back("shristi");
	v.push_back("sadhna");
	v.push_back("abhishek");

	sort(v.begin(), v.end()); // by default sorting is done in lexicographically inc. order

	for (string name : v) {
		cout << name << " ";
	}

	cout << endl;

	// sort(v.rbegin(), v.rend());
	sort(v.begin(), v.end(), greater<string>());

	for (string name : v) {
		cout << name << " ";
	}

	cout << endl;


	return 0;
}