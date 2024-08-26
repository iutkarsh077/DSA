#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a = "Hello";
    cout << a << endl;
    a.erase(a.begin(), a.end());
    if(a.empty()){
        cout << "Empty" << endl;
    }
    return 0;
}