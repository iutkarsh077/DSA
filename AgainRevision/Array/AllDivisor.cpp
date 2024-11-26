#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int calDiv(int val)
{
    int sum = 0;

    for (int i = 1; i <= val; i++)
    {
        if (val % i == 0)
        {
            sum += i;
        }
    }

    return sum;
}

void BruteMethode()
{
    int val = 0;
    int result = 0;
    for (int i = 1; i <= val; i++)
    {

        result += calDiv(i);
    }

    cout << result;
}

int main()
{
    int n = 6;
    vector<int> sum(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            sum[j] += i;
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        result += sum[i];
    }

    cout << result;
    return 0;
}