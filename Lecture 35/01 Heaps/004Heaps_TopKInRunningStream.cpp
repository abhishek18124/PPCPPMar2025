/*

Given an infinite stream of non-negative integers, design an algorithm to output the
top-K integers every time you encounter -1.

Example : Input = 4, 1, 2, -1, 3, -1 7 0 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8
                   . . .

*/

#include<iostream>
#include<queue>

#define pqmin priority_queue<int, vector<int>, greater<int>>

using namespace std;

void printMinHeap(pqmin minHeap) {
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {

    int k = 3;
    pqmin minHeap;

    for (int i = 1; i <= k; i++) { // assume you won't get -1 during heap init
        int val; cin >> val;
        minHeap.push(val);
    }

    while (true) {
        int val; cin >> val;
        if (val == 0) { // stream has ended
            break;
        } else if (val == -1) {
            // print the elements of the minHeap
            printMinHeap(minHeap);
        } else {
            if (val > minHeap.top()) {
                // track val in the minHeap
                minHeap.pop();
                minHeap.push(val);
            }
        }
    }

    return 0;
}