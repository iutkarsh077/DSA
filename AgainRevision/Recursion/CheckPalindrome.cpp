#include<iostream>
using namespace std;

bool IsPalindrome(string ans, int i){
    if(i >= ans.length() - i - 1) return true;

    if(ans[i] != ans[ans.length() - 1 - i]) return false;

    return IsPalindrome(ans, i + 1);
}

int main() {
    string ans = "abcba";
    bool result = IsPalindrome(ans, 0);
    if(result){
        cout << "It is a Palindrome String";
    }

    else{
        cout << "No, It is not a Palindrome String";
    }

    return 0;
}