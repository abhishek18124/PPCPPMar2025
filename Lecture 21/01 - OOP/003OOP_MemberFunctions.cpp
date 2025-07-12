#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	void print() {
		cout << "name = " << name << endl;
		cout << "gender = " << gender << endl;
		cout << "age = " << age << endl;
		cout << "credits = " << credits << endl << endl;
	}

};

int main() {

	customer c1;

	c1.name = "Ramanujan";
	c1.age = 32;
	c1.gender = 'M';
	c1.credits = 1729;

	c1.print(); // when you call print on c1, then addr of c1 is implicitely passed during the fn call

	customer c2;

	c2.name = "Aryabhata";
	c2.age = 74;
	c2.gender = 'M';
	c2.credits = 0;

	c2.print(); // when you call print on c2, then addr of c2 is implicitely passed during the fn call

	return 0;
}