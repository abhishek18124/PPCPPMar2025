/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class maxHeap {

	vector<int> v;

	void heapify(int i) { // fixes the heap property at the node corr. to idx i

		int maxIdx = i;

		int leftChildIdx = 2 * i + 1;
		if (leftChildIdx < v.size() and v[leftChildIdx] > v[maxIdx]) {
			maxIdx = leftChildIdx;
		}

		int rightChildIdx = 2 * i + 2;
		if (rightChildIdx < v.size() and v[rightChildIdx] > v[maxIdx]) {
			maxIdx = rightChildIdx;
		}

		if (maxIdx != i) { // we'll hit the base case when maxIdx becomes equal to i
			swap(v[i], v[maxIdx]);
			heapify(maxIdx);
		}

	}

public:

	// time : O(logn)

	void push(int val) {
		v.push_back(val);
		int childIdx  = v.size() - 1;
		int parentIdx = childIdx % 2 == 0 ? childIdx / 2 - 1 : childIdx / 2;
		while (childIdx != 0 and v[childIdx] > v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = childIdx % 2 == 0 ? childIdx / 2 - 1 : childIdx / 2;
		}
	}

	// time : O(logn)

	void pop() { // assume heap is non-empty, calling pop() on empty heap is undefined
		swap(v[0], v[v.size() - 1]); // const
		v.pop_back(); // const
		heapify(0); // logn
	}

	// time : O(1)

	int top() { // assume heap is non-empty, calling top() on empty heap is undefined
		return v[0];
	}

	// time : O(1)

	int size() {
		return v.size();
	}

	// time : O(1)

	bool empty() {
		return v.empty();
	}

};

int main() {

	maxHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl; // 9

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl; // 0

	return 0;
}



