#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "coding";

	cout << "s[" << 0 << "] = " << s[0] << endl;
	cout << "s[" << 1 << "] = " << s[1] << endl;
	cout << "s[" << 2 << "] = " << s[2] << endl;
	cout << "s[" << 3 << "] = " << s[3] << endl;
	cout << "s[" << 0 << "] = " << s[4] << endl;
	cout << "s[" << 5 << "] = " << s[5] << endl << endl;

	for (int i = 0; s[i] != '\0'; i++) {
		cout << "s[" << i << "] = " << s[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < s.size(); i++) {
		cout << "s[" << i << "] = " << s[i] << endl;
	}

	cout << s.front() << " " << s[0] << endl;
	cout << s.back() << " " << s[s.size() - 1] << endl;

	return 0;
}