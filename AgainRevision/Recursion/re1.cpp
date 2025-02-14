#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

double myPow(double x, int n)
{
    if (x == 0)
    {
        return 0;
    }

    double result = 1;
    long long int duplicate = n;

    if (duplicate < 0)
    {
        duplicate = -duplicate;
        x = 1 / x;
    }

    while (duplicate > 0)
    {
        if (duplicate % 2 == 1)
        {
            result *= x;
        }

        x *= x;
        duplicate /= 2;
    }
    return result;
}

int main()
{
    return 0;
}