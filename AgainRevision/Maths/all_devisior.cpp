#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n = 4;
    vector<int> v;
    for (int i = 1; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (i != n / i)
            {
                v.push_back(n/i);
            }
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}