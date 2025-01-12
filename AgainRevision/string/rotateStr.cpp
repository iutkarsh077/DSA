#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s = "abcde";
    string goal = "";
    int index = -1;
    int val = goal[0];

    for (int i = 0; i < s.size(); i++)
    {
        if (val == s[i])
        {
            index = i;
            break;
        }
    }

    string ans = "";

    for (int i = index; i < s.size(); i++)
    {
        ans += s[i];
    }

    for (int i = 0; i < index; i++)
    {
        ans += s[i];
    }

    if (ans == goal)
    {
        cout << true;
        return true;
    }

    cout << false;
    return 0;
}