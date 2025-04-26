#include<iostream>
#include<cstring> // for memset

using namespace std;

int main() {

	int A[] = {10, 20, 30, 40, 50}; // specifying size of the arr[] during init is optional

	cout << A[0] << " "
	     << A[1] << " "
	     << A[2] << " "
	     << A[3] << " "
	     << A[4] << endl;

	int n = sizeof(A) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	// int B[5] = {100, 200, 300, 400, 500, 600}; // error : size of initialzer list shouldn't exceed size of the array

	int C[5] = {1000, 2000, 3000};

	for (int i = 0; i < 5; i++) {
		cout << C[i] << " ";
	}

	cout << endl;

	int D[5] = {0};

	for (int i = 0; i < 5; i++) {
		cout << D[i] << " ";
	}

	cout << endl;

	int E[5] = {};

	for (int i = 0; i < 5; i++) {
		cout << E[i] << " ";
	}

	cout << endl;

	int F[5];

	memset(F, 0, sizeof(F));

	for (int i = 0; i < 5; i++) {
		cout << F[i] << " ";
	}

	cout << endl;

	int G[5];

	memset(G, -1, sizeof(G));

	for (int i = 0; i < 5; i++) {
		cout << G[i] << " ";
	}

	cout << endl;

	int H[5];

	memset(H, 2, sizeof(H));

	for (int i = 0; i < 5; i++) {
		cout << H[i] << " ";
	}

	cout << endl;

	// memset can only be used to init array with either 0 or -1
	// since it assigns values byte-wise

	int K[5];

	for (int i = 0; i < 5; i++) {
		K[i] = 2;
	}

	for (int i = 0; i < 5; i++) {
		cout << K[i] << " ";
	}

	cout << endl;

	return 0;
}