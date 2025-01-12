#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

 bool rotateString(string s, string goal) {
        for (int i = 0; i < s.size(); i++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal)
                return true;
        }
        return false;
    }

int main()
{
    string s = "abcde";
    string goal = "bcdea";
    for (int i = 0; i < s.size(); i++)
    {
        rotate(s.begin(), s.begin() + 1, s.end());
        if(s == goal) return true;
    }
    return false;
    return 0;
}