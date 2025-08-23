#include<iostream>
#include<list>

using namespace std;

template <typename T>
class queue {

	list<T> dll;

public:

	void push(T val) {
		dll.push_back(val); // insertion at tail
	}

	void pop() {
		dll.pop_front(); // deletion at head
	}

	T front() {
		return dll.front(); // value of head
	}

	int size() {
		return dll.size();
	}

	bool empty() {
		return dll.empty(); // head == NULL
	}

};

int main() {

	queue<int> q;

	cout << "size : " << q.size() << endl;
	cout << "empty : " << q.empty() << endl;

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();
	q.empty() ? cout << "queue is empty!" << endl : cout << "queue is not empty!" << endl;

	return 0;
}