#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n = 11;

    int cnt = 0;

    if (n == 1)
    {
        cout << "No it is not a prime number";
        return 0;
    }
    bool flag = true;
    for (int i = 2; i * i <= n; i++)
    {
       
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }

    if (flag == true)
    {
        cout << "It is a prime number";
    }
    else
    {
        cout << "No, it is not a prime number";
    }
    return 0;
}