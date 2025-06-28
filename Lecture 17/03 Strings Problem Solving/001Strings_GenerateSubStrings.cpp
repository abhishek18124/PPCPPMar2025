#include<iostream>
#include<string>

using namespace std;

void generateSubstrings(string str, int n) {

	for (int i = 0; i <= n - 1; i++) {
		for (int j = i; j <= n - 1; j++) {
			// generate the substring that starts at the ith index
			// and ends at the jth index
			string subString = str.substr(i, j - i + 1);
			cout << subString << endl;
		}
		cout << endl;
	}

}

int main() {

	string str = "abcde";
	int n = str.size();

	generateSubstrings(str, n);

	return 0;
}