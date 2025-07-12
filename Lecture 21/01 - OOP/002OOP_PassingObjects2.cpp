#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

};

void modifyAge(customer& c) { // here customer obj is passed by ref therefore any changes done to the parameter will be reflected in the argument
	c.age++;
}

int main() {

	customer c1;

	c1.name = "Ramanujan";
	c1.age = 32;
	c1.gender = 'M';
	c1.credits = 1729;

	cout << c1.age << endl;

	modifyAge(c1);

	cout << c1.age << endl;

	return 0;
}