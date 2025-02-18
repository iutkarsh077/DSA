#include <bits/stdc++.h>
using namespace std;


void printNumbers(int n, int i){
    if(i > n) return;

    cout << i << endl;
    printNumbers(n, i + 1);
}

int main() {
    printNumbers(10, 1);
    return 0;
}