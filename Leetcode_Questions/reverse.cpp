#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

 int reverse(int x) {
        int y = 0;
        while(x != 0){
            int n = x % 10;
            if(y < INT_MIN/10 || y > INT_MAX/10){
                return 0;
            }
            y = (y  * 10) + n;
            x = x / 10;
        }
        return y;
    }

int main() {
    cout << reverse(12345678);
    cout << endl << INT_MAX  << endl << INT_MIN  << endl;
    cout << pow(2, 31);
    return 0;
}