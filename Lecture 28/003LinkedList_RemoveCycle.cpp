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

void insertAtHead(ListNode*& head, int val) {

	ListNode* n = new ListNode(val);
	n->next = head;
	head = n;

}


void printLinkedList(ListNode* head) {

	while (head) { // head != NULL
		cout << head->val << " ";
		head = head->next;
	}

	cout << endl;
}

void removeCycle(ListNode* head) { // we are assuming linkedList has >= 2 nodes and it contains a cycle

	ListNode* slow = head;
	ListNode* fast = head;

	while (true) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			break;
		}
	}

	// at this point, slow & fast are at the meeting point

	ListNode* prev = head;
	while (prev->next != fast) {
		prev = prev->next;
	}

	// at this point, prev is one step behind meeting point

	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
		prev = prev->next;
	}

	// at this point of time slow & fast are at the start of the cycle
	// and prev is at the tail of the linkedList
	prev->next = NULL; // this removes the cycle

}

int main() {

	ListNode* head = new ListNode(10);
	head->next = new ListNode(20);
	head->next->next = new ListNode(30);
	head->next->next->next = new ListNode(40);
	head->next->next->next->next = new ListNode(50);
	head->next->next->next->next->next = new ListNode(60);
	head->next->next->next->next->next->next = head->next;

	removeCycle(head);

	printLinkedList(head);

	return 0;
}