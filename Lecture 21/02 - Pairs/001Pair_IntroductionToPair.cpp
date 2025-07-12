/*
		https://cplusplus.com/reference/utility/pair/?kw=pair

		This 'pair' class couples together a pair of values, which maybe of different
		types (T1 and T2).The individual values of a pair can be accessed through its
		public members first and second.
*/

#include<iostream>
#include<utility>

using namespace std;

int main() {

	pair<int, int> p1;

	p1.first = 10;
	p1.second = 20;

	cout << p1.first << " " << p1.second << endl;

	pair<string, int> p2 = {"Akshat", 20};

	cout << p2.first << " " << p2.second << endl;

	pair<char, int> p3 = make_pair('X', 0);

	cout << p3.first << " " << p3.second << endl;

	pair<string, string> p4;

	cin >> p4.first >> p4.second;

	cout << p4.first << " " << p4.second << endl;

	return 0;
}