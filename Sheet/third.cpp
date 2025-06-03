#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal)
{
    for (int i = 0; i < s.size(); i++)
    {
        rotate(s.begin(), s.begin() + 1, s.end());
        if (s == goal)
            return true;
    }
    return false;
}



int main()
{
    string a = "abcde";
    rotate(a.begin(), a.begin() + 1, a.end());
    cout << a;
    return 0;
}