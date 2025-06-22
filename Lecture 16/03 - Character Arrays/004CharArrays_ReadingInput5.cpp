// n <= 100

#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[101]; // based on constraints

	cin.getline(str, 101); // '\n' is the default delimiting character

	cout << str << endl;

	// [HW] think of a way we can ignore the leading whitespaces in the input string when using cin.getline

	return 0;
}