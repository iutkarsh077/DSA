#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s =  "a good   example";

    int i = 0;
    int n = s.length();
    string result = "";
    while(i < n){
        if(s[i] == ' '){
            i++;
            continue;
        }

        int j = i + 1;
        string word = "";
        word += s[i];
        while(j < n && s[j] != ' '){
            word += s[j];
            j++;
        }
        i = j + 1;
        result = word + ' ' + result;
    }

    result.pop_back();
    for(int i = 0; i < result.length(); i++){
        if(result[i] == ' '){
            cout << 1;
        }

        else{
            cout << result[i];
        }
    }
    return 0;
}