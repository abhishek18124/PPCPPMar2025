/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {

	map<string, vector<string>> phoneMap;

	phoneMap["Akshat"].push_back("1234");
	phoneMap["Akshat"].push_back("5678");
	phoneMap["Harjas"].push_back("0000");
	phoneMap["Harjas"].push_back("1111");
	phoneMap["Sarthak"].push_back("123");

	for (pair<string, vector<string>> contact : phoneMap) {
		string contactName = contact.first;
		vector<string> phoneNums = contact.second;
		cout << contactName << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (auto [contactName, phoneNums] : phoneMap) {
		cout << contactName << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}