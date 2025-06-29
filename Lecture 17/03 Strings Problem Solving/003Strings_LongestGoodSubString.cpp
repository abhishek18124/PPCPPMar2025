#include<iostream>
#include<string>

using namespace std;

bool isGoodString(const string& str) { // here we are passing str by const& to avoid copy and to make sure we don't modify str within the function

	for (char ch : str) {
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is consonant, therefore given string is not good
			return false;
		}
	}

	// given string is a good string
	return true;

}

// time : O(n^3)
// space: O(n) due substring

int longestGoodSubstring(const string& str) {

	int maxSofar = 0;
	int n = str.size();

	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {
			// check if the substring that starts at the ith index
			// and ends at the jth index is a good substring or not
			string substring = str.substr(i, j - i + 1);
			if (isGoodString(substring)) {
				maxSofar = max(maxSofar, j - i + 1);
			}
		}
	}

	return maxSofar;

}

int main() {

	string str = "cbaeicdeiou";

	cout << longestGoodSubstring(str) << endl;

	return 0;
}