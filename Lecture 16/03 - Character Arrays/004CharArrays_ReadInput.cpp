// n <= 100

#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[101]; // based on constraints

	cin >> str;

	// cin >> ignores leading whitespaces but

	// cin >> stops reading input as soon as it encounters
	// a non-leading whitespace character

	cout << str << endl;

	cout << strlen(str) << endl;

	// cout << sizeof(str) / sizeof(char) << endl;

	return 0;
}