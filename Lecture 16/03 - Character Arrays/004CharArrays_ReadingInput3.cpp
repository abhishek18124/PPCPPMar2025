// n <= 100

#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[101]; // based on constraints

	// we'll read input till we encounter '$' or we've read 5B of data
	// which includes the '\0' character

	cin.getline(str, 5, '$');

	cout << str << endl;

	return 0;
}