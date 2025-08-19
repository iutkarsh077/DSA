#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

void countDigits()
{
    long long n = 8726786278;
    int logResult = (int)(log10(n) + 1);
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count = count + 1;
    }
    cout << "The number of digits are: " << count;
}

void reverseNumber()
{
    long long int n = 1534236469;
    long long int result = 0;

    while (n > 0)
    {
        int digit = n % 10;
        result = (result * 10) + digit;
        n = n / 10;
    }

    cout << "The result is: " << result;
}

bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    long long int val = 0;
    int dupX = x;
    while (dupX > 0)
    {
        int digit = dupX % 10;
        val = (val * 10) + digit;
        dupX = dupX / 10;
    }

    if (val == x)
        return true;

    return false;
}

int countNumberLength(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

int powerNumber(int n, int power)
{
    if (power <= 0)
        return 1;

    if (power % 2 == 0)
    {
        return powerNumber(n, power / 2) * powerNumber(n, power / 2);
    }
    else
    {
        return n * powerNumber(n, power / 2) * powerNumber(n, power / 2);
    }
}

void armStrong(){
    int n = 152;
    int dupN = n;
    int ans = 0;
    int count = countNumberLength(n);
    while(n > 0){
        int digit = n % 10;
        ans += powerNumber(digit, count);
        n = n /10;
    }
    cout << "Answer is: " << ans;

    if(ans == dupN){
        cout << endl << "Number is Palindrome";
    }
    else{
        cout << endl << "No, its not a Palindrome";
    }
}

void GCD(){
    int n1 = 30;
    int n2 = 45;
    int mini = min(n1, n2);
    int ans = 1;

    for(int i = 1; i <= mini; i++){
        if(n1 % i == 0 && n2 % i == 0){
            ans = max(ans, i);
        }
    }

    cout << "GCD is: " << ans;
}

int main()
{
    GCD();
    return 0;
}