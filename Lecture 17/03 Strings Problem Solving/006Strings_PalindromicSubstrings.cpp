#include<iostream>
#include<string>

using namespace std;

bool isPalindrome(const string& s) {

	int i = 0;
	int j = s.size() - 1;

	while (i < j) {

		if (s[i] != s[j]) {
			return false; // s is not a palindrome
		}

		i++;
		j--;

	}

	// s is palindrome
	return true;

}

// time : O(n^3)
// space: O(n) due substring

int countPalindromicSubstrings(const string& s) {

	int cnt = 0; // to track the no. of palindromic substrings in the given string

	for (int i = 0; i < s.size(); i++) {
		for (int j = i; j < s.size(); j++) {
			// check if the substring that starts at the ith index and
			// ends at the jth index is a palindrome or not
			string substring = s.substr(i, j - i + 1);
			if (isPalindrome(substring)) {
				cnt++;
			}
		}
	}

	return cnt;

}

// time : O(n^2)
// space: O(1)

int countPalindromicSubstringsOptimised(const string& s) {

	int n = s.size();

	int cnt = 0; // to track no. of palindromic substrings in s

	// 1. find no. of odd-length palindromic substrings in s

	for (int i = 0; i < n; i++) {

		// find out no. of odd-length palindromic substrings with s[i] as the center

		int j = 0;
		while (i - j >= 0 and i + j <= n - 1 and s[i - j] == s[i + j]) {
			j++;
			cnt++;
		}

	}

	// 2. find no. of even-length palindromic substrings in s

	for (double i = 0.5; i < n; i++) {

		// find out no. of even-length palindromic substrings with i as the center

		double j = 0.5;
		while (i - j >= 0 and i + j <= n - 1 and s[(int)(i - j)] == s[(int)(i + j)]) {
			j++;
			cnt++;
		}

	}

	return cnt;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstrings(s) << endl;

	cout << countPalindromicSubstringsOptimised(s) << endl;

	return 0;
}