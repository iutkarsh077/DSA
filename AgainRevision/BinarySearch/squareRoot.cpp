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

    long long int minVal = -1;
    long long int n = 17123044;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    long long int s = 0;
    long long int e = n / 2;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (mid * mid <= n)
        {
            minVal = mid;
            s = mid + 1;
        }

        else if (mid * mid > n)
        {
            e = mid - 1;
        }
    }

    

    cout << minVal;
    return 0;
} 