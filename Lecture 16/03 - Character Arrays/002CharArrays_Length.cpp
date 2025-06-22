#include<iostream>
#include<cstring>

using namespace std;

int findLength(char str[]) { // char[] is by default passed by reference
	int cnt = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		cnt++;
	}
	return cnt;
}

int main() {

	char str[] = "coding";

	cout << findLength(str) << endl;

	cout << strlen(str) << endl;

	char str2[100] = "hello";

	cout << strlen(str2) << endl;

	cout << sizeof(str2) / sizeof(char) << endl; // this is not the right way to find the length of the string

	return 0;
}