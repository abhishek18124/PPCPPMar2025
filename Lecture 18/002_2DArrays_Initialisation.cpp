#include<iostream>

using namespace std;

int main() {

    int arr[3][4] = {
        {10, 15, 20, 25},
        {30, 35, 40, 45},
        {50, 55, 60, 65}
    };

    cout << arr[0][1] << endl; // 15
    cout << arr[1][2] << endl; // 40
    cout << arr[2][3] << endl; // 65

    // during init of a 2d array, specifying no. of rows is optional
    // but specifying no. of columns is mandatory

    int brr[][4] = {
        {100, 200, 300, 400},
        {500, 600, 700, 800}
    };

    cout << sizeof(brr) << "B" << endl;

    cout << brr[0][1] << endl; // 200
    cout << brr[1][2] << endl; // 700

    int crr[][4] = {
        {1000, 2000, 3000, 4000},
        {5000, 6000}
    };

    cout << crr[1][0] << endl; // 5000
    cout << crr[1][1] << endl; // 6000
    cout << crr[1][2] << endl; // 0 (default int value)
    cout << crr[1][3] << endl; // 0 (default int value)


    return 0;
}