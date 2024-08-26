#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

/*
int main()
{
    char c = 'z';
    // char a = tolower(c);
    if ((int)c > 60 && (int)c < 126)
    {

        cout << (int)c << endl;
        // return 0;
    }
    // cout << "Not typecasting";

    char a = '9';
    cout << int(a);
    return 0;
}
*/

bool isPalindrome(string s)
{
    string a = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (((int)s[i] >= 65 && (int)s[i] <= 90) || ((int)s[i] >= 48 && (int)s[i] <= 57) ||((int)s[i] >= 97 && (int)s[i] <= 122))
        {
            char b = tolower(s[i]);
            a += b;
        }
    }

    int i = 0;
    int j = a.length() - 1;
    while (i < j)
    {
        if (a[i] != a[j])
        {
            cout << (int)a[i] << " " << (int)a[j] << endl;
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main(){
    bool flag = isPalindrome("ab_a");
    cout << flag;
    return 0;
}