#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;


string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void sayDigit(int x, string engNumber){
    if(x <= 0){
        return;
    }

    int digit = x % 10;
    string digitInEng = words[digit];
    x = x / 10;
    sayDigit(x, digitInEng);
    cout << digitInEng << " ";
}


int main() {
    int x = 12345;
    if(x == 0){
        cout << "zero";
        return 0;
    }
    sayDigit(x, "");
    return 0;
}   