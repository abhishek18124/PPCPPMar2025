#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name;
	int age;
	char gender;
	double credits;

	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}
};

// return true if you want a to be ordered before b otherwise return false

bool agecmp(customer a, customer b) {
	if (a.age < b.age) {
		// since we are sorting customers by age in the inc. order
		// when a.age is less than b.age we want a to be ordered
		// before b therefore we are returning true
		return true;
	}
	return false;
}

class AGECMP {

public:

	// return true if you want a to be ordered before b otherwise return false

	bool operator()(customer a, customer b) {
		if (a.age < b.age) {
			// since we are sorting customers by age in the inc. order
			// when a.age is less than b.age we want a to be ordered
			// before b therefore we are returning true
			return true;
		}
		return false;
	}

};

int main() {

	vector<customer> v;

	// customer c1("Ramanujan", 32, 'M', 1729);
	// v.push_back(c1);

	v.push_back(customer("Ramanujan", 32, 'M', 1729));
	v.push_back(customer("JC Bose", 78, 'M', 2500));
	v.push_back(customer("Aryabhata", 74, 'M', 0));
	v.push_back(customer("Vikram", 52, 'M', 1500));
	v.push_back(customer("Homi", 56, 'M', 1000));

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	cout << endl;

	// sort(v.begin(), v.end(), agecmp); // agecmp is a function ptr

	AGECMP obj; // obj is a function object i.e. it is callable

	sort(v.begin(), v.end(), obj);

	// sort(v.begin(), v.end(), AGECMP());

	for (customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	cout << endl;

	return 0;
}