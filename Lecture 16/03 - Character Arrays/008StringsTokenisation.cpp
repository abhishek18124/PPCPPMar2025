#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[] = "a?b$c.de$?.f.ghi";
	char dlim[] = ".?$";

	char* ptr = strtok(str, dlim);

	while (ptr != NULL) {
		cout << ptr << endl;
		ptr = strtok(NULL, dlim);
	}

	return 0;
}