#include <bits/stdc++.h>
using namespace std;

int main()
{
    string val = "1111";
    int ans = 0;

    for (int i = val.length() - 1; i >= 0; i--)
    {
        if (val[i] == '1')
        {
            int myval = pow(2, val.length() - 1 - i);
            ans += myval;
        }
    }
    cout << ans;
    return 0;
}