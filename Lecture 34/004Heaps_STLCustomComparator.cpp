/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class customer {

public:
	string name;
	int age;

	customer(string name, int age) {
		this->name = name;
		this->age = age;
	}

};

class customerAgeComp {

public:

	// // return true if you want a to be ordered before b
	// // otherwise return false

	// bool operator()(customer a, customer b) {
	// 	if (a.age < b.age) {
	// 		// since we are building a minHeap based on customer
	// 		// age when age of customer a is less than age of
	// 		// customer b we want a to be ordered before b
	// 		return true;
	// 	}
	// 	return false;
	// }

	// return false if you want a to be given more priority than b
	// otherwise return true

	bool operator()(customer a, customer b) {
		if (a.age < b.age) {
			// since we are building a minHeap based on customer
			// age when age of customer a is less than age of
			// customer b we want a to be given more priority than b
			return false;
		}
		return true;
	}

};

int main() {

	priority_queue<customer, vector<customer>, customerAgeComp> m;

	m.push(customer("utsav", 20));
	m.push(customer("mansi", 19));
	m.push(customer("sarthak", 21));
	m.push(customer("harjas", 18));
	m.push(customer("keya", 17));

	cout << m.size() << endl; // 5

	while (!m.empty()) {
		customer c = m.top();
		cout << c.name << " " << c.age << endl;
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl; // 0

	return 0;
}