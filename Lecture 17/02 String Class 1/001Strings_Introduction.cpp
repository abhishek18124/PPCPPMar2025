#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1 = "coding blocks"; // string initialisation
	cout << s1 << endl;

	string s2; // string declaration

	cout << s2.size() << endl;
	s2.empty() ? cout << "true" << endl : cout << "false" << endl;

	s2 = "hello world"; // string assignment
	cout << s2 << endl;
	cout << s2.size() << endl;

	return 0;

}