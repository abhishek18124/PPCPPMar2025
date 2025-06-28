#include<iostream>
#include<cstring>

using namespace std;

// time : n/2.const ~ O(n)
// space: O(1)

bool isPalindrome(char str[]) {

	int i = 0;
	int j = strlen(str) - 1;

	while (i < j) {
		if (str[i] == str[j]) {
			i++;
			j--;
		} else {
			return false; // str[] is not a palindrome
		}
	}

	return true; // str[] is a palindrome

}

int main() {

	char str[] = "abcdefcba";

	isPalindrome(str) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}