/*

	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset

	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values

*/

#include<iostream>
#include<set>

using namespace std;

int main() {

	multiset<int> s; // vector<int> v;

	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(1); // 1 will be inserted again since multiset<> supports duplicates

	cout << "size : " << s.size() << endl; // 6

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(5); // since 5 exists in the set<>, it will be erased

	cout << "size : " << s.size() << endl; // 5

	// if you try to erase an element which doesn't
	// exist in the set<>, nothing will happen

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	// you can also erase values from a set<> using
	// iterators to those values

	auto it = s.begin();
	s.erase(it);

	cout << "size : " << s.size() << endl; // 4

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	it = s.begin();

	it++;

	it = s.erase(it);

	cout << *it << endl;

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	if (s.find(3) != s.end()) {
		cout << "3 is present" << endl;
	} else {
		cout << "3 is absent" << endl;
	}

	if (s.find(2) != s.end()) {
		cout << "2 is present" << endl;
	} else {
		cout << "2 is absent" << endl;
	}

	if (s.count(5)) {
		cout << "5 is present" << endl;
	} else {
		cout << "5 is absent" << endl;
	}

	if (s.count(4)) {
		cout << "4 is present" << endl;
	} else {
		cout << "4 is absent" << endl;
	}

	s.clear(); // all elements will be erased

	cout << "size : " << s.size() << endl; // 0

	s.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}