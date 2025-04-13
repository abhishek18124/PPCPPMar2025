#include<iostream>

using namespace std;

int main() {

	int cnt = 0; // to track the cnt of non-negative nos.
	int data;

	while (true) {
		cin >> data;
		if (data < 0) {
			break;
		}
		cnt++;
	}

	cout << "cnt = " << cnt << endl;

	return 0;
}