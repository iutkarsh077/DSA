#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "()()";
    string ans = "";
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            cnt++;

        else if (s[i] == ')')
            cnt--;

        if ((s[i] == '(' && cnt == 1) || cnt == 0)
        {
            continue;
        }

        else
        {
            ans += s[i];
        }
    }

    cout << ans;
    return 0;
}