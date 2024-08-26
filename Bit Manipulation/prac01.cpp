#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n =862;
    int val = 0;
    while(n >= 1){
        int ans = n % 2;
        val = (val * 10) + ans;
        n = n / 2;
    }

    cout << val << endl;
    string str = to_string(val);
    // reverse(str.begin(), str.end());
    int i = 0;
    int result = 0;
    while(i < str.length()){
        if(str[i] == '0'){
            result = result + 0;
        }
        else{
            result = result + pow(2, i);
        }

        i++;
    }  
    cout << result;
    return 0;
}