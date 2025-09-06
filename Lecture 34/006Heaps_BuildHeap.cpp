/*

	Given an array of n integers, design a O(n) algorirthm to build a max_heap in-place.

*/

#include<iostream>
#include<vector>

using namespace std;

// [HW] try to implement heapify iteratively

void heapify(vector<int>& v, int n, int i) { // fixes the heap property at the node corr. to idx i

	int maxIdx = i;

	int leftChildIdx = 2 * i + 1;
	if (leftChildIdx < n and v[leftChildIdx] > v[maxIdx]) {
		maxIdx = leftChildIdx;
	}

	int rightChildIdx = 2 * i + 2;
	if (rightChildIdx < n and v[rightChildIdx] > v[maxIdx]) {
		maxIdx = rightChildIdx;
	}

	if (maxIdx != i) { // we'll hit the base case when maxIdx becomes equal to i
		swap(v[i], v[maxIdx]);
		heapify(v, n, maxIdx);
	}

}

int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	// time : O(n)

	// iterate from leaf to root and invoke heapify
	// to transform the array into a heap

	for (int i = n - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}





