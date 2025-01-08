#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s) {
        int i = 0;
        string ans = "";

        while(i < s.length()){
            string words = "";
            int j = i;
            while(j < s.length() && s[j] != ' '){
                words += s[j];
                j++;
            }

            if(words.length() > 0){
                ans = words + ' ' + ans;
            }
            i = j + 1;
        }

        ans.pop_back();
        return ans;
    }

int main() {
    return 0;
}