#include<iostream>

using namespace std;

int main() {

	int marks;
	cin >> marks;

	if (marks >= 91 and marks <= 100) {
		cout << "Grade A" << endl;
	} else if (marks >= 81 and marks <= 90) {
		cout << "Grade B" << endl;
	} else if (marks >= 71 and marks <= 80) {
		cout << "Grade C" << endl;
	} else if (marks >= 61 and marks <= 70) {
		cout << "Grade D" << endl;
	} else if (marks >= 51 and marks <= 60) {
		cout << "Grade E" << endl;
	} else {
		cout << "Grade F" << endl;
	}

	cout << "you are outside the if-else-if block" << endl;

	return 0;
}