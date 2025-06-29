#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

// return true if you want a to be ordered before b
// otherwise return false

bool cmp(string a, string b) {
	if (a.size() < b.size()) {
		// since we are sorting by length in the inc. order
		// we want a to be ordered before b when a.size() is
		// less than b.size()
		return true;
	}
	return false;
}

int main() {

	vector<string> v;

	v.push_back("tanmay");
	v.push_back("yash");
	v.push_back("yatharth");
	v.push_back("abhay");
	v.push_back("sarthak");

	// sort(v.begin(), v.end()); // by default sorting is done in lexicographically inc. order
	sort(v.begin(), v.end(), cmp);

	for (string name : v) {
		cout << name << " ";
	}

	cout << endl;

	return 0;
}