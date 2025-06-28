#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	string s;
	getline(cin >> ws, s);
	cout << s << endl;

	// cin >> ws is an input manipulator that can be used to
	// ignore leading whitespaces

	return 0;
}