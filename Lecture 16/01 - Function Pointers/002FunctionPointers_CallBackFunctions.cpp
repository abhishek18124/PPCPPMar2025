#include<iostream>

using namespace std;

bool ascending(int a, int b) {
	return a > b; // return true when a > b otherwise return false
}

bool descending(int a, int b) {
	return a < b; // return true when a < b otherwise return true
}

void bubbleSort(int* arr, int n, bool (*f)(int, int)) { // using (*f)(...) in parameter list is optional, we can use f(...)

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < n - i; j++) {
			if (f(arr[j], arr[j + 1])) { // (*f)(arr[j], arr[j+1])
				swap(arr[j], arr[j + 1]);
			}
		}
	}

}

// void bubbleSort(int* arr, int n, bool f(int, int)) {

// 	for (int i = 1; i <= n - 1; i++) {
// 		for (int j = 0; j < n - i; j++) {
// 			if (f(arr[j], arr[j + 1])) { // (*f)(arr[j], arr[j+1])
// 				swap(arr[j], arr[j + 1]);
// 			}
// 		}
// 	}

// }


int main() {

	int arr[] = {1, 0, 3, 2, 4};
	int n = sizeof(arr) / sizeof(int);

	bubbleSort(arr, n, ascending);
	// bubbleSort(arr, n, &ascending);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	bubbleSort(arr, n, descending);
	// bubbleSort(arr, n, &descending);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}