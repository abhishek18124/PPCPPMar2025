/*

Given two strings s1 and s2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters
(can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example :

	Input : s1 = "ATGC", s2 = "AGCT"
	Output: 3
	Explanation : "AGC" is the LCS between s1 and s2

	Input : s1 = "AGGTAB", s2 = "GXTXAYB"
	Output: 4
	Explanation : “GTAB” is the LCS between s1 and s2

*/

#include<iostream>
#include<vector>

using namespace std;

int f(const string& s1, const string& s2, int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) {

		// f(m, j) = find the length of the lcs b/w s1[m...m-1] i.e. "" and s2[j...n-1]

		// f(i, n) = find the length of the lcs b/w s1[i...m-1] and s2[n...n-1] i.e. ""

		return 0;
	}

	// recursive case

	// f(i, j) = find the length of the lcs b/w s1[i...m-1] and s2[j...n-1]

	if (s1[i] == s2[j]) {
		return 1 + f(s1, s2, m, n, i + 1, j + 1);
	}

	return max(f(s1, s2, m, n, i + 1, j), f(s1, s2, m, n, i, j + 1));

}

// time : O(mn)
// space: O(mn) due to dp[][], can be optimised to O(n)

int fBottomUp(const string& s1, const string& s2, int m, int n) {
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 0 init handles base case // w/o zero init you've explictely set the mth row and nth col to zero as those cells corr. to base case

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			// dp[i][j] = f(i, j)
			if (s1[i] == s2[j]) {
				dp[i][j] = 1 + dp[i + 1][j + 1];
			} else {
				dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	return dp[0][0]; // at the 0,0th index of dp[][] we store f(0, 0)
}

int main() {

	string s1("AAAA");
	string s2("AAAA");

	int m = s1.size();
	int n = s2.size();

	cout << f(s1, s2, m, n, 0, 0) << endl;

	cout << fBottomUp(s1, s2, m, n) << endl;

	return 0;
}