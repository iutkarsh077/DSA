#include <bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
    int count = 0;

    if (n == 0)
        return 1;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }

    return count;
}

int reverse(int x)
{
    long long val = 0;
    long long dupN = x;

    if (dupN < 0)
    {
        dupN = dupN * -1;
    }
    while (dupN > 0)
    {
        int digit = dupN % 10;
        val = (val * 10) + digit;
        dupN = dupN / 10;
    }

    if (x < 0)
    {
        val = val * -1;
    }

    if (val < INT_MIN || val > INT_MAX)
    {
        return 0;
    }

    return (int)val;
}

int gcd(int a, int b)
{
    if (a == b)
        return a;
    while (a > 0 && b > 0)
    {
        if (a < b)
        {
            b = b % a;
        }
        else
        {
            a = a % b;
        }
    }

    if (a <= 0)
        return b;
    return a;
}


int main()
{
    return 0;
}