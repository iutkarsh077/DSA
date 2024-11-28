#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class Date26Nov2024
{
public:
    int fibo(int n)
    {
        if (n == 0)
        {
            return 0;
        }

        if (n == 1)
        {
            return 1;
        }

        return fibo(n - 1) + fibo(n - 2);
    }
};

int main()
{

    int n = 4;

    Date26Nov2024 first;
    int result = first.fibo(n);

    cout << result;
    return 0;
}