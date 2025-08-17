#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> s) {

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

}

void insertAtBottom(stack<int>& s, int val) {

	// base case
	if (s.empty()) {
		s.push(val);
		return;
	}

	// recursive case

	int x = s.top();
	s.pop();
	insertAtBottom(s, val);
	s.push(x);

}

int main() {

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	print(s);

	int val = 0;

	insertAtBottom(s, val);

	print(s);

	return 0;
}