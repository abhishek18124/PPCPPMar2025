#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

// time : O(nlogn) since we are using map<>
// time : n.on avg. const ~ on avg. O(n) but worst case O(n^2) if unordered_map<> is used
// space : O(n) due to map<> or unordered_map<>

bool isDuplicatePresent(const vector<int>& v) {

	map<int, int> freqMap;
	for (int x : v) {
		freqMap[x]++;
		if (freqMap[x] > 1) {
			// duplicate found
			return true;
		}
	}

	// for (pair<int, int> p : freqMap) {
	// 	int el = p.first;
	// 	int fr = p.second;
	// 	cout << "freq(" << el << ") = " << fr << endl;
	// }

	// no duplicate found

	return false;

}

bool isDuplicatePresentUsingSet(const vector<int>& v) {

	set<int> s(v.begin(), v.end());
	if (s.size() < v.size()) {
		// duplicates found
		return true;
	} else {
		// no duplicates found
		return false;
	}

}

// time : O(nlogn) since we are using a set<>
// time : unordered_set<> a.k.a hash set, each op is on avg. const but worst case linear
// space: O(n) due to set<>

bool isDuplicatePresentUsingSet2(const vector<int>& v) {

	set<int> s;
	for (int x : v) {
		if (s.find(x) == s.end()) {
			// x is not yet present, so insert it
			s.insert(x);
		} else {
			// x is already present in the set<> so you've found duplicate
			return true;
		}
	}

	// no duplicates found
	return false;

}

int main() {

	vector<int> v = {1, 2, 3};

	isDuplicatePresent(v) ? cout << "true" << endl : cout << "false" << endl;

	isDuplicatePresentUsingSet(v) ? cout << "true" << endl : cout << "false" << endl;

	isDuplicatePresentUsingSet2(v) ? cout << "true" << endl : cout << "false" << endl;


	return 0;
}