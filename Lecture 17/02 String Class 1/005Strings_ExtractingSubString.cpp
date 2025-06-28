#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "coding";

	string ss = s.substr(3, 2);
	cout << ss << endl;
	cout << s.substr(3, 2) << endl; // starting from idx 3 we extract a substring of length 2
	cout << s.substr(3) << endl; // starting from idx 3 we extract all the characters

	return 0;
}