#include <bits/stdc++.h>
using namespace std;

void CountNumber(int n)
{
    int cnt = 0;
    int dupn = abs(n);

    if (dupn == 0)
    {
        cout << "The number " << n << " has " << 1 << " numbers";
        return;
    }

    while (dupn > 0)
    {
        cnt++;
        dupn = dupn / 10;
    }

    cout << "The number " << n << " has " << cnt << " numbers";
}

int reverse(int x)
{
    int ans = 0;
    int isPositive = x > 0 ? 1 : -1;
    if (x >= INT_MAX || x <= INT_MIN)
        return 0;
    int dup = abs(x);

    while (dup > 0)
    {
        int digit = dup % 10;
        if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
        {
            return 0;
        }

        ans = ans * 10 + digit;
        dup = dup / 10;
    }

    return ans * isPositive;
}

int gcd(int a, int b){
    while(a > 0 && b > 0){
        if(a > b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }

    cout << max(a, b);
}

void allDivisor(int n){
    vector<int> nums;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            nums.push_back(i);
        }
    }

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}

void CheckPrimeNumber(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            cout << "No, its not a prime number" << endl;
            return;
        }
    }

    cout << "Yes, Its a prime number";
}

int main()
{
    // CountNumber(-675675);
    // gcd(12, 9);
    CheckPrimeNumber(3);
    return 0;
}