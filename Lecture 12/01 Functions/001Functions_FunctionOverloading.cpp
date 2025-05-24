#include<iostream>
#include<cmath>

using namespace std;

float areaOfTriangle(int b, int h) {
	cout << "1st" << endl;
	return 0.5 * b * h;
}

float areaOfTriangle(float b, int h) {
	cout << "2nd" << endl;
	return 0.5 * b * h;
}

float areaOfTriangle(double b, int h) {
	cout << "3rd" << endl;
	return 0.5 * b * h;
}

float computeSemiPerimeter(int a, int b, int c) {
	return 0.5 * (a + b + c);
}

float areaOfTriangle(int a, int b, int c) {
	cout << "4th" << endl;
	float s = computeSemiPerimeter(a, b, c);
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

// int f(int a, int b) {
// 	return a * b;
// }

// int f(int a, int b) {
// 	return a + b;
// }

int main() {

	cout << areaOfTriangle(4, 5) << endl;
	cout << areaOfTriangle(4.0f, 5) << endl;
	cout << areaOfTriangle(4.0, 5) << endl;
	cout << areaOfTriangle(3, 4, 5) << endl;

	// cout << f(2, 3) << endl;

	return 0;
}