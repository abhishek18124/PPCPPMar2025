#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// vector<int> f(const vector<int>& A) {

// 	int n = A.size();
// 	vector<int> ans(n, -1);
// 	stack<pair<int, int>> s; // <value, index> // to track elements for which we are yet to find the nearest greater element to their right

// 	for (int i = 0; i < n; i++) {

// 		// find out the elements for which A[i] can be the
// 		// nearest greater element to their right

// 		while (!s.empty() and A[i] > s.top().first) {
// 			// A[i] is the nearest greater element for s.top().first
// 			ans[s.top().second] = A[i];
// 			s.pop();
// 		}

// 		s.push({A[i], i});

// 	}

// 	return ans;

// }

vector<int> f(const vector<int>& A) {

	int n = A.size();
	vector<int> ans(n, -1);
	stack<int> s; // <index> // to track elements for which we are yet to find the nearest greater element to their right

	for (int i = 0; i < n; i++) {

		// find out the elements for which A[i] can be the
		// nearest greater element to their right

		while (!s.empty() and A[i] > A[s.top()]) {
			// A[i] is the nearest greater element for s.top().first
			ans[s.top()] = A[i];
			s.pop();
		}

		s.push(i);

	}

	return ans;

}

int main() {

	vector<int> A = {5, 3, 6, 7, 2, 1, 4};

	vector<int> ans = f(A);
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}