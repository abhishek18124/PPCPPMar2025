#include<iostream>
#include<string>

using namespace std;

bool isGoodString(const string& str) { // here we are passing str by const& to avoid copy and to make sure we don't modify str within the function

	// for (int i = 0; i < str.size(); i++) {
	// 	char ch = str[i];
	// 	if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
	// 		// ch is consonant, therefore given string is not good
	// 		return false;
	// 	}
	// }

	for (char ch : str) {
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is consonant, therefore given string is not good
			return false;
		}
	}

	// given string is a good string
	return true;

}

int main() {

	string str = "uoxea";

	isGoodString(str) ? cout << "good string" << endl :
	                         cout << "not good string" << endl;

	return 0;
}