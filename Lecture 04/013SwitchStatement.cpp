#include<iostream>

using namespace std;

int main() {

	char grade;
	cin >> grade;

	// if (grade == 'A') {
	// 	cout << "very good" << endl;
	// } else if (grade == 'B') {
	// 	cout << "good" << endl;
	// } else if (grade == 'C') {
	// 	cout << "avg" << endl;
	// } else if (grade == 'D') {
	// 	cout << "poor" << endl;
	// } else if (grade == 'E') {
	// 	cout << "very poor" << endl;
	// } else if (grade == 'F') {
	// 	cout << "fail" << endl;
	// } else {
	// 	cout << "invalid grade" << endl;
	// }

	switch (grade) { // we can only switch char or int
	case 'A': cout << "very good" << endl; break;
	case 'B': cout << "good" << endl; break;
	case 'C': cout << "avg" << endl; break;
	case 'D': cout << "poor" << endl; break;
	case 'E': cout << "very poor" << endl; break;
	case 'F': cout << "fail" << endl; break;
	default: cout << "invalid" << endl;
	}

	return 0;
}