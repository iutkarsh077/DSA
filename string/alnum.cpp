#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // char ch = ':';
    // if (isalnum(ch)) {
    //     std::cout << ch << " is alphanumeric.\n";
    // } else {
    //     std::cout << ch << " is not alphanumeric.\n";
    // }

    /*string s = "A man, a plan, a canal: Panama";
     string val;
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                char ch = tolower(s[i]);
                val = val + ch;
            }
        }
        cout << val;*/

    string val = "amanaplanacanalpanama";
    string val2 = val;

    reverse(val.begin(), val.end());

    if(val2 == val){
        cout << true;
        return 0;
    }

    cout << false;
    return 0;
}
