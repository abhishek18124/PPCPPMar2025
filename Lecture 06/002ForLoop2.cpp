#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1, j = n; i < j; i++, j--) {
		cout << i << " " << j << endl;
	}

	return 0;
}