#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s1 = "zxabd";

	sort(s1.begin(), s1.end()); // string is sorted in inc. order

	cout << s1 << endl;

	// sort(s1.rbegin(), s1.rend());
	sort(s1.begin(), s1.end(), greater<char>());

	cout << s1 << endl;

	return 0;
}