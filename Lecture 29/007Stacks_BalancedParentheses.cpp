
// https://leetcode.com/problems/valid-parentheses/

#include<iostream>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n) due to stack

class Solution {
public:
	bool isValid(string str) {
		stack<char> s;
		for (char ch : str) {
			switch (ch) {
			case '(':
			case '[':
			case '{': s.push(ch); break;
			case ')': if (!s.empty() and s.top() == '(') s.pop(); else return false; break;
			case ']': if (!s.empty() and s.top() == '[') s.pop(); else return false; break;
			case '}': if (!s.empty() and s.top() == '{') s.pop(); else return false; break;
			}
		}
		return s.empty();
	}
};

int main() {

	string s = "([{}])";

	Solution().isValid(s) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}