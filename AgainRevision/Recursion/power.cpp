#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int PowerofTwo(int i){
    if(i == 1) return 2;

    return 2 * PowerofTwo(i - 1);
}

void addTwoTillHundred(int i){
    if(i > 100) return;

    cout << i << endl;

    addTwoTillHundred(i + 2);
}


void printNumber(int i){
    if(i == 0) return;

    cout << i << endl;
    printNumber(i - 1);
}

int main() {
    // int ans = PowerofTwo(20);
    // cout << ans;
    // printNumber(5);
    addTwoTillHundred(0);
    return 0;
}