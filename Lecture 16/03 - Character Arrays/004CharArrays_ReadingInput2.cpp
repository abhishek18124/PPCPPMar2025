// n <= 100

#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[101]; // based on constraints

	// we'll read input till we encounter '$'
	// here, '$' is the delimiting char

	cin.getline(str, 101, '$'); // i/p coding bl$ocks o/p : coding bl

	cout << str << endl;

	return 0;
}