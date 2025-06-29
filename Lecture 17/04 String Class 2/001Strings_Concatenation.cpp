#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "abc";
	string s2 = "def";

	s1 = s1 + s2;

	cout << s1 << endl;
	cout << s2 << endl;

	string s3 = "wxy";

	// s3 = s3 + string(1, 'z');
	s3.push_back('z');
	cout << s3 << endl;

	s3.pop_back();
	cout << s3 << endl;

	return 0;
}