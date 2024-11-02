#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m)
{

    if (m == 1)
    {
        return 1;
    }
    if (n == 1)
    {
        return m;
    }
    long long int minVal = -1;
    for (long long int i = 0; i <= m / 2; i++)
    {
        if (pow(i, n) == m)
        {
            minVal = i;
        }
    }

    return minVal;
}

int main()
{
    int n = 3;
    int m = 126;
    if (m == 1)
    {
        return 1;
    }
    if (n == 1)
    {
        return m;
    }
    long long int minVal = -1;

    int s = 0;
    int e = m / 2;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        if (m == pow(mid, n))
        {
            minVal = mid;
            break;
        }

        else if (pow(mid, n) < m)
        {
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }
    }

    cout << minVal;
    return 0;
}