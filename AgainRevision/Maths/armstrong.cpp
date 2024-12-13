#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n = 11;
    int dup_num = n;

    int result = 0;
    while (dup_num > 0)
    {
        int digit = dup_num % 10;
        result += digit * digit * digit;
        dup_num = dup_num / 10;
    }

    if (result == n)
    {
        cout << "True it is armstrong number";
    }
if (result == n)
    {
        cout << "True it is armstrong number";
    }
    else
    {
        cout << "No, it is not armstrong number";
    }
    return 0;
}