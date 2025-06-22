// n <= 50 and m <= 50

#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char s1[101] = "abc";
	char s2[] = "def";

	cout << s1 << endl;

	strcat(s1, s2); // concatenates / attaches s2 to s1

	cout << s1 << endl;

	return 0;
}