#include<iostream>

using namespace std;

int main() {

	int cnt = 0; // to track the no. of characters

	char ch;

	while (true) {

		// cin >> ch; // cin>> ignores whitespace character

		ch = cin.get(); // cin.get() reads whitespaces (' ', '\n', '\t')

		if (ch == '$') {
			break;
		}

		cnt++;

	}

	cout << "cnt = " << cnt << endl;

	return 0;
}