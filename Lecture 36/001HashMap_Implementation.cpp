/*

	Implementation of HashMap/HashTable

*/

#include<iostream>

using namespace std;

class node {

public :

	int K;
	int V;
	node* next;

	node(int K, int V) {
		this->K = K;
		this->V = V;
		this->next = NULL;
	}

};

class HashMap {
	int N; //  to store the hash table capacity
	int M; //  to store the hash table size
	double L; // to store the load factor threshold

	node** T; // to store the pointer to the  dynamic
	// array that represents the hash table

	int hashFn(int K) {
		// transform K into a hash index
		return K % N;
	}

	void transfer(node* head) {
		// 1. rehash (K, V) pairs present in the linkedList represented
		//    by "head" pointer to the updated hashMap
		node* temp = head;
		while (temp != NULL) {
			insert(temp->K, temp->V);
			temp = temp->next;
		}

		// 2. release memory allocated for the linkedList represented
		//    by "head" pointer
		while (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	void rehash() {

		// 1. save pointer to the current hashMap and its capacity

		node** oldT = T;
		int oldN = N;

		// 2. create a hashMap with double capacity

		N = 2 * N;
		T = new node*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL;
		}
		M = 0;

		// 3. transfer (K, V) pairs from old hashMap to the updated hashMap

		for (int i = 0; i < oldN; i++) {
			transfer(oldT[i]);
		}

		// 4. release the memory allocated to the old hashMap

		delete [] oldT;

	}

public :

	HashMap(int N = 5, double L = 0.7) {
		this->N = N;
		this->M = 0;
		this->L = L;

		T = new node*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL;
		}
	}

	void insert(int K, int V) {

		// 1. transform the key into hash index using the hash function

		int hashIdx = hashFn(K);

		// 2. create a node with the given (K, V) pair and insert it at
		//    head of the linkedList stored at the hash index

		node* n = new node(K, V);

		// 3. update the pointer to the head of the linkedList stored at
		//    the hash index such that it holds the address of the newly
		//    created node

		n->next = T[hashIdx];
		T[hashIdx] = n;
		M++;

		// 4. rehash, if loadFactor exceeds the loadFactor Threshold

		double LF = (double)M / N;
		if (LF > L) {
			cout << "rehashing due to LF = " << LF << endl;
			rehash();
		}

	}

	node* find(int K) {

		// 1. transform the key into hash index using the hash function
		int hashIdx = hashFn(K);

		// 2. search for the node with the given key in the  linkedList
		//    stored at the hash index
		node* temp = T[hashIdx];
		while (temp != NULL) {
			if (temp->K == K) {
				break;
			}
			temp = temp->next;
		}

		return temp;

	}

	void erase(int K) {

		// 1. transform the key into hash index using the hash function

		int hashIdx = hashFn(K);

		// 2. delete the node with the given key from the linkedList
		//    stored at the hash index

		node* temp = T[hashIdx];
		if (temp == NULL) {
			// linkedList at the hashIdx is empty so key doesn't exist
			// in the hashMap
			return;
		} else {
			if (temp->K == K) {
				// key found at the head of the linkedList maintained at hashIdx so delete head node
				T[hashIdx] = temp->next;
				delete temp;
				M--;
			} else {
				// key, if present, will be at a non-head node so find and delete it
				node* prev = NULL;
				while (temp != NULL) {
					if (temp->K == K) {
						prev->next = temp->next;
						delete temp;
						M--;
						break;
					}
					prev = temp;
					temp = temp->next;
				}
			}
		}

	}

	void printLinkedList(node* head) {
		while (head != NULL) {
			cout << "(" << head->K << ", " << head->V << ") ";
			head = head->next;
		}
		cout << endl;
	}

	void printHashMap() {
		// iterate over buckets in the hashMap
		for (int i = 0; i < N; i++) {
			// print the linkedList stored ith bucket of the hashMap
			cout << i << " : ";
			printLinkedList(T[i]);
		}
		cout << endl;
	}

	int& operator[](int K) {
		node* n = find(K);
		if (n == NULL) {
			insert(K, 0);
			n = find(K);
		}
		return n->V;
	}
};

int main() {

	HashMap hm;

	hm.insert(2, 4);
	hm.insert(7, 49);
	hm.insert(3, 9);

	hm.printHashMap();

	hm.insert(6, 36);

	hm.printHashMap();

	cout << hm[2] << endl; // 4 // hm.operator[](2)
	cout << hm[6] << endl; // 36
	// cout << hm[10] << endl; // hm.operator[](10)

	// hm[10] = 100;
	// hm.operator[](10) = 100;

	hm[6] = 0;
	// hm.operator[](6) = 0;
	// 36 = 0;

	cout << hm[6] << endl;

	hm.printHashMap();

	hm[10] = 100;
	// hm.operator[](10) = 100;

	hm.printHashMap();

	hm[6] = 36;
	// hm.operator[](6) = 36;

	hm.printHashMap();

	return 0;
}