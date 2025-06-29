#include<iostream>
#include<string>

using namespace std;

int main() {

	string str = "cbaeicdeiou";

	int cnt = 0; // to track no. of consecutive vowels we've seen
	int maxSofar = 0; // to track the length of the longest good substring

	// time : O(n)
	// space: O(1)
	// [HW] try to build the longest good substring

	for (char ch : str) {

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			cnt++;
			maxSofar = max(maxSofar, cnt);
		} else {
			cnt = 0;
		}

	}

	cout << maxSofar << endl;

	return 0;
}