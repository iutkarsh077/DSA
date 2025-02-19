#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0) return 1;

    return n * factorial(n - 1);
}

int main()
{
    long long int result = factorial(16);
    cout << result;
    return 0;
}