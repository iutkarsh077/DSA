#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n = 23;

    int cnt = 0;
    int dup = n;

    while (dup > 0)
    {
        int digit = dup % 10;
        if (digit != 0 && n % digit == 0)
        {
            cnt++;
        }
        dup = dup / 10;
    }

    cout << cnt;
    return 0;
}