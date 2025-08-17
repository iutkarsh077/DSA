#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;

void countDigits(){
    long long n = 8726786278;
    int logResult = (int)(log10(n) + 1);
    int count = 0;
    while(n > 0){
        n = n / 10;
        count = count + 1;
    }
    cout << "The number of digits are: " << count;
}

void reverseNumber(){
    long long int n = 1534236469;
    long long int result = 0;

    while(n > 0){
        int digit = n % 10;
        result = (result * 10) + digit;
        n = n / 10;
    }

    cout << "The result is: " << result;
}

int main(){
    reverseNumber();
    return 0;
}