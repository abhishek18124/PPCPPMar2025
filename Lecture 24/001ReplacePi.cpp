/*

Given string str of size n, design a recursive algorithm to replace all
occurrences of "pi" with "3.14" in the given string and then print it.

Example :
	Input : inp[] = "pippppiiiipi"
	Output: out[] = "3.14ppp3.14iii3.14"

	Input : inp[] = "pip"
	Output: out[] = "3.14p"

	Input : inp[] = "xpix"
	Output: out[] = "x3.14x"

Constraints :

	1 < n < 10

*/

#include<iostream>

using namespace std;

void f(char inp[], int i) {

	// base case

	if (inp[i] == '\0') {
		return;
	}

	// recursive case

	// f(i) = a fn that replaces all the "pi" with "3.14"
	// in the inp[i...n-1]

	if (inp[i] == 'p' and inp[i + 1] == 'i') {

		// 1. replace "pi" at the i,i+1th index with "3.14"

		// 1.a. shift all the characters starting from index i+2 two-steps fwd

		int j = i + 2;
		while (inp[j] != '\0') {
			j++;
		}

		while (j >= i + 2) {
			inp[j + 2] = inp[j];
			j--;
		}

		// 1.b. now replace "pi" at the i,i+1th index with "3.14"

		inp[i] = '3';
		inp[i + 1] = '.';
		inp[i + 2] = '1';
		inp[i + 3] = '4';

		// 2. ask your friend to replace all the "pi" with "3.14"
		// in inp[i+4...n-1]

		f(inp, i + 4);

	} else {

		// ask your friend to replace all the "pi" with "3.14" in
		// the inp[i+1...n-1]

		f(inp, i + 1);

	}

}

int main() {

	char inp[20] = "pipipipi";

	f(inp, 0);

	cout << inp << endl; // 3.14p

	return 0;
}
