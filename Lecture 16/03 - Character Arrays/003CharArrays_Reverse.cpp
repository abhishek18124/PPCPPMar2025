#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {

	char str1[] = "hello";
	int n = strlen(str1);

	cout << str1 << endl;

	reverse(str1, str1 + n);

	cout << str1 << endl;

	char str2[] = "coding";
	int m = strlen(str2);

	cout << str2 << endl;

	reverse(str2 + 1, str2 + 5); // reverses str2[] in the range [2, 5)

	cout << str2 << endl;

	return 0;
}