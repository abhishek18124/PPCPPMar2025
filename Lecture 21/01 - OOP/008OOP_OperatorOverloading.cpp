#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

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

	// int operator+(customer c) { // here c2 is passed by value
	// 	return age + c.age;
	// }

	// int operator+(customer& c) { // here c2 is passed by ref
	// 	return age + c.age;
	// }

	int operator+(const customer& c) { // here c2 is passed by const-ref
		return age + c.age;
	}

	int operator*(customer c) { // we are overloading operator* as a member function
		return age * c.age;
	}

};

int operator-(customer c1, customer c2) { // we are overloading operator- as a non-member function
	return c1.age - c2.age;
}

int main() {

	customer c1("Ramanujan", 32, 'M', 1729);
	customer c2("Aryabhata", 74, 'M', 0);

	cout << (c1 + c2) << endl; // c1.operator+(c2)

	// addr of c1 is passed automatically during this fn call
	// and c2 is passed as an argument during this fn call

	cout << (c1 * c2) << endl; // c1.operator*(c2)

	cout << (c1 - c2) << endl; // c1.operator-(c2) // operator-(c1, c2)

	return 0;

}