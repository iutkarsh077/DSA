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

int countGoodNumbers(long long n)
{
    long long int start = 1;
    string startStr = to_string(start);
    long long int count = 1;
    unordered_map<int, int> mp;
    mp.insert({2, 1});
    mp.insert({3, 1});
    mp.insert({5, 1});
    mp.insert({7, 1});

    while(startStr.size() <= n){
        int i = 0;
        while(i < startStr.size()){
            int val = startStr[i] - '0';

            if(val % 2 == 0 && i % 2 == 0){
                count++;
                i++;
            }
            else if((mp.find(val) != mp.end()) && (mp.find(i) != mp.end())){
                count++;
                i++;
            }
            else{
                break;
            }
        }
        start = start + 1;
        startStr = to_string(start);
    }
    return count % MOD;
}

int main()
{
    long long int ans = countGoodNumbers(4);
    cout << ans;
    return 0;
}