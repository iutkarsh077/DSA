#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

long long int floorSqrt(long long int n)
{
    // Your code goes here
    int minVal = -1;
    for (int i = 0; i <= n / 2; i++)
    {
        if (i * i <= n)
        {
            minVal = i;
        }
    }
    return minVal;
}

int main()
{
    return 0;
}