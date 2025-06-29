#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "abcde";

	// reverse(s.begin(), s.end());
	reverse(s.begin() + 1, s.begin() + 3);

	cout << s << endl;

	return 0;
}