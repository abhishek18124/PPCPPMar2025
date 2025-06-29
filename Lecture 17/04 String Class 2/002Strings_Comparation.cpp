#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1, s2;
	cin >> s1 >> s2;

	if (s1 == s2) {
		cout << "equal" << endl;
	} else if (s1 > s2) {
		cout << "s1 is greater" << endl;
	} else {
		cout << "s2 is greater" << endl;
	}

	return 0;
}