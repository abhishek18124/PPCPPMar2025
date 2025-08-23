#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// time : O(n)
// space: O(n) due to monotonic stack

vector<int> f(const vector<int>& A) {

	stack<int> s;
	vector<int> ans;
	int n = A.size();

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest greater element to the right of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no greater element to the rigth of A[i]
			ans.push_back(-1);
		} else {
			// whatever is at the top of the stack is the
			// nearest greater element to the right of A[i]
			ans.push_back(s.top());
		}

		s.push(A[i]);

	}

	reverse(ans.begin(), ans.end());

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