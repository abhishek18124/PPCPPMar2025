#include<iostream>
#include<string>

using namespace std;

// time : O(n^2)
// space: O(1)

int findRudeness(const string& str) {

	int rudeness = 0;

	for (int i = 0; i < str.size(); i++) {

		if (str[i] == 'a') {

			// find out no. of b's in str[i+1...n-1]

			for (int j = i + 1; j < str.size(); j++) {

				if (str[j] == 'b') {
					rudeness++;
				}

			}

		}

	}

	return rudeness;

}

// time : O(n)
// space: O(1)

int findRudenessOptimised(const string& str) {

	int rudeness = 0;
	int cntb = 0;

	for (int i = str.size() - 1; i >= 0; i--) {

		if (str[i] == 'a') {
			rudeness += cntb;
		} else if (str[i] == 'b') {
			cntb++;
		}

	}

	return rudeness;

}

int main() {

	string str = "ababbaab";

	cout << findRudeness(str) << endl;

	cout << findRudenessOptimised(str) << endl;

	return 0;
}