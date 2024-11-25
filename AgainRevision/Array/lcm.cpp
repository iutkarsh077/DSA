#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b)
{
    while (b > 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
vector<long long> lcmAndGcd(int a, int b)
{
    long long val = gcd(max(a, b), min(a, b));
    long long lcm = (a * b) / val;

    return {lcm, val};
}

int main()
{
    vector<long long> result = lcmAndGcd(14, 8);

    cout << "Lcm is: " << result[0] << " " << "GCD is: " << result[1];
    return 0;
}