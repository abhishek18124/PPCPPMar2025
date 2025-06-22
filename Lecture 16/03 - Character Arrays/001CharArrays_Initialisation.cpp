#include<iostream>

using namespace std;

int main() {

	char str1[] = {'a', 'b', 'c', 'd', 'e', '\0'};
	cout << str1 << endl;

	char str2[] = "abcde"; // '\0' is added automatically when you init char[] with string literal
	cout << str2 << endl;

	char str3[] = "coding";

	cout << str3[0] << endl; // c
	cout << str3[1] << endl; // o
	cout << str3[2] << endl; // d
	cout << str3[3] << endl; // i
	cout << str3[4] << endl; // n
	cout << str3[5] << endl << endl; // g

	for (int i = 0; str3[i] != '\0'; i++) {
		cout << str3[i] << endl;
	}

	// char str4[5] = "hello"; // during init if you specify the size of the char[], make sure that the size accomodates the '\0' character

	return 0;
}