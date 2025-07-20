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

	set<int, greater<int>> s; // vector<int> v;

	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(1); // ignored since set<> contains distinct elements

	cout << "size : " << s.size() << endl; // 5

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	return 0;
}