#include<iostream>

using namespace std;

class customer {

public :

	string name;
	int age;
	char gender;
	double credits;

	customer() {
		cout << "\nI am inside the default constructor of the customer class\n";
	}

	void print() {
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "gender = " << gender << endl;
		cout << "credits = " << credits << endl;
	}
};

int main() {

	customer c1; // default constructor of the customer class is invoked to create c1

	customer c2; // default constructor of the customer class is invoked to create c2

	return 0;
}