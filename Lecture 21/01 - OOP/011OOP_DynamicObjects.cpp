#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer() {
		cout << "\ninside the default constructor of the \'customer\' class\n" << endl;
	}

	customer(string n, int a, char g, double c) {
		cout << "\ninside the parameterised constructor of the \'customer\' class\n" << endl;
		name = n;
		age = a;
		gender = g;
		credits = c;
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl << endl;
	}

};

int main() {

	customer* cptr1 = new customer;

	cin >> cptr1->name;
	cin >> cptr1->age;
	cin >> cptr1->gender;
	cin >> cptr1->credits;

	cptr1->print();

	customer* cptr2 = new customer("Ramanujan", 32, 'M', 1729);

	cptr2->print();

	return 0;
}