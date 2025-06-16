#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

// double myPow(double x, int n)
// {
//     double ans = pow(x, n);
//     return ans;
// }

//  double ansPow(double x, int n){
//         if(n == 1) return x;
//         if(n == 0) return 1;

//         if(n % 2 == 0){
//             return ansPow(x, n / 2) * ansPow(x, n / 2);
//         }
//         else{
//             return x * ansPow(x, n / 2) * ansPow(x, n / 2);
//         }
//     }

//     double myPow(double x, int n) {
//         return ansPow(x, n);
//     }

//      double ansPowNeg(double x, int n) {
//         if (n == 1)
//             return x;
//         if (n == 0)
//             return 1;

//          double half = ansPowNeg(x, n / 2);
//         if (n % 2 == 0) {
//             return half * half;
//         } else {
//             return x * half * half;
//         }
//     }

//     double myPowNeg(double x, int n) {
//         long nn = n;
//         if (n < 0) {
//             nn = -1 * nn;
//             return 1.0 / ansPowNeg(x, nn);
//         }
//         return ansPowNeg(x, nn);
//     }

int myAtoi(string s)
{
    int i = 0;
    long long int ans = 0;
    int sign = 1;
    int n = s.size();

    while (i < n && s[i] == ' ')
        i++;

    if (i < n && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }

    while (i < n && isdigit(s[i]))
    {
        ans = (ans * 10) + (s[i] - '0');

        if (sign * ans > INT_MAX)
            return INT_MAX;
        if (sign * ans < INT_MIN)
            return INT_MIN;

        i++;
    }

    return sign * ans;
}

int findPower(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }

    long long half = findPower(a, b / 2);
    long long result = (half * half) % MOD;

    if (b % 2 == 1)
    {
        result = (result * a) % MOD;
    }

    return result;
}



int countGoodNumbers(long long n)
{
    return (long long)findPower(5, (n + 1) / 2) * findPower(4, n / 2) % MOD;
}

int main()
{
   
    return 0;
}