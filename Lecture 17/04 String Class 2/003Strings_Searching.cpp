#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcabcab";

	cout << s.find("ca") << endl;
	cout << s.rfind("ca") << endl;

	cout << s.find("xyz") << endl;
	cout << string::npos << endl;

	if (string::npos == -1) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}

	return 0;
}