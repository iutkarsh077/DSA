#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int arr[4][5] = {
        {0, 1, 2, 3, 9},
        {1, 2, 3, 4, 4},
        {2, 3, 4, 5, 4},
        {3, 4, 5, 6, 6}};
    cout << sizeof(arr) << endl;
    cout << "Row is: " << sizeof(arr) / sizeof(arr[0]) << endl;
    cout << "Column is: " << sizeof(arr[0]) / sizeof(int);
    return 0;
}