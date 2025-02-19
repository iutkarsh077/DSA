#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int PowerofTwo(int i){
    if(i == 1) return 2;

    return 2 * PowerofTwo(i - 1);
}

int main() {
    int ans = PowerofTwo(20);
    cout << ans;
    return 0;
}