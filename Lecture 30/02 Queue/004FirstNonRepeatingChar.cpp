#include<iostream>
#include<queue>

using namespace std;

int main() {

	char ch;

	int freqMap[26] = {0};
	queue<char> q;

	while (true) {

		cin >> ch;
		freqMap[ch - 'a']++;
		if (freqMap[ch - 'a'] == 1) {
			// ch, as of now, is a non-repeating char so track it in the queue
			q.push(ch);
		}

		// now find the 1st non-repeating char. in the stream after reading ch

		while (!q.empty() and freqMap[q.front() - 'a'] > 1) {
			// char at the front of the queue is now repeating, so remove it
			q.pop();
		}

		if (q.empty()) {
			// there are no non-repeating chars in the stream
			cout << -1 << " ";
		} else {
			// whatever is at the front of the queue is the 1st non-repeating
			// character in the stream
			cout << q.front() << " ";
		}

	}

	return 0;
}