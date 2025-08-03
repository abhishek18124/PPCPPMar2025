#include<iostream>

using namespace std;

class ListNode {

public:

	int val;
	ListNode* next;

	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}

};

void insertAtHead(ListNode*& headRef, int val) { // head ptr is passed by reference
	// to make sure any changes done to headRef in this fn is reflected in the head
	// ptr maintained in the main fn

	ListNode* n = new ListNode(val);
	n->next = headRef;
	headRef = n;

}

void printLinkedList(ListNode* head) { // head ptr is passed by value

	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;

}

int main() {

	ListNode* head = NULL; // linkedList is empty

	insertAtHead(head, 50);
	insertAtHead(head, 40);
	insertAtHead(head, 30);
	insertAtHead(head, 20);
	insertAtHead(head, 10);

	if (head == NULL) {
		cout << "YES" << endl;
	}

	printLinkedList(head); // 10 20 30 40 50

	printLinkedList(head);

	return 0;

}