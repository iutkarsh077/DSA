#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s)
{
    int i = 0;
    string ans = "";

    while (i < s.length())
    {
        string words = "";
        int j = i;
        while (j < s.length() && s[j] != ' ')
        {
            words += s[j];
            j++;
        }

        if (words.length() > 0)
        {
            ans = words + ' ' + ans;
        }
        i = j + 1;
    }

    ans.pop_back();
    return ans;
}

string largestOddNumber(string num)
{
    string ans = "";
    int n = num.size();

    for (int i = n - 1; i >= 0; i--)
    {
        int val = num[i] - '0';
        if (val % 2 != 0)
        {
            ans = num.substr(0, i + 1);
            break;
        }
    }

    return ans;
}

int main()
{
    return 0;
}