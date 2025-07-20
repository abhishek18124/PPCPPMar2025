#include<iostream>
#include<set>

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

class ageCmp {

public:

	// return true if you want a to be ordered before
	// b otherwise return false

	bool operator()(customer a, customer b) const {
		if (a.age < b.age) {
			// since we are sorting customers based on
			// age in the inc. order when a.age is <
			// b.age we want a to be ordered before b
			return true;
		}
		return false;
	}

};

int main() {


	set<customer, ageCmp> s;

	s.insert(customer("Akshat", 20));
	s.insert(customer("Harjas", 19));
	s.insert(customer("Yatharth", 21));
	s.insert(customer("Lavanya", 18));

	for (customer c : s) {
		cout << c.name << " " << c.age << endl;
	}

	cout << endl;

	return 0;
}