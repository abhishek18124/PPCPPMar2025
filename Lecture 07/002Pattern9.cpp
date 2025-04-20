#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		// for the ith row, print n-i+1 char. in the
		// inc. order starting with 'A'

		char ch = 'A';

		for (int j = 1; j <= n - i + 1; j++) {
			cout << ch;
			ch++;
		}

		// print n-i+1 more char. in the dec. order starting
		// with the char. with which inc. pattern ended

		ch--;

		for (int j = 1; j <= n - i + 1; j++) {
			cout << ch;
			ch--;
		}

		cout << endl;

	}

	return 0;
}