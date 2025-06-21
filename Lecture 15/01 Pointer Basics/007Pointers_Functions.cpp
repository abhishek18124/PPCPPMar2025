#include<iostream>

using namespace std;

void increment(int* ptr) {
  (*ptr)++;
}

int main() {

  int a = 10;

  cout << "inside main(), before increment() a = " << a << endl;

  int* ptr = &a;
  increment(ptr);

  cout << "inside main(), after  increment() a = " << a << endl;

  return 0;
}