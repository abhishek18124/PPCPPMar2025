#include<iostream>

using namespace std;

// time : n + n + 26 = 2n + 26 ~ O(n)
// space: 26 + 26 for f1[] and f2[] ~ O(1) assuming n >>> 26

bool isAnagram(char s1[], char s2[]) {

	// 1. build a frequency map for s1[]

	int f1[26] = {0};

	for (int i = 0; s1[i] != '\0'; i++) {
		char ch = s1[i];
		int idx = ch - 'a';
		f1[idx]++;
	}

	// for (int i = 0; i < 26; i++) {
	// 	cout << f1[i] << " ";
	// }

	// cout << endl;

	// 2. build a frequency map for s2[]

	int f2[26] = {0};
	for (int i = 0; s2[i] != '\0'; i++) {
		f2[s2[i] - 'a']++;
	}

	// for (int i = 0; i < 26; i++) {
	// 	cout << f2[i] << " ";
	// }

	// cout << endl;

	// 3. compare the two frequency maps

	for (int i = 0; i < 26; i++) {
		if (f1[i] != f2[i]) {
			// frequency of char mapped to the ith index
			// does not in s1[] and s2[] therefore s1[]
			// and s2 are not anagrams
			return false;
		}
	}

	// s1[] and s2[] are anagrams
	return true;

}

int main() {

	char s1[] = "aabbbcc";
	char s2[] = "aabbbcc";

	isAnagram(s1, s2) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}