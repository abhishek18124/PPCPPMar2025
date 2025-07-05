#include<vector>
#include<iostream>

using namespace std;

int main() {

	// vector<int> v; // v is a vector of int

	// vector<vector<int>> v; // v is a vector of vector<int>

	// vector<int> v(3); // v is a vector of int of size 3

	// vector<int> v(3, 1); // v is a vector of int of size 3 init with 1

	// vector<vector<int>> v(3, vector<int>(4));

	// int m = v.size(); // no. of rows
	// int n = v[0].size();  // no. of cols

	// for (int i = 0; i < m; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << v[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	vector<vector<int>> v(3, vector<int>(4, 1));

	int m = v.size(); // no. of rows
	int n = v[0].size();  // no. of cols

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}