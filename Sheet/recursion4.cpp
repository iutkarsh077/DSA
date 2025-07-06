#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

void reachSchool(int src, int dest)
{
    if (src == dest)
    {
        cout << "Reached School" << endl;
        return;
    }

    cout << "Covered distance: " << src << endl;

    reachSchool(src + 1, dest);
}

void fibo(int n, int first, int second)
{
    if (n == 2)
        return;

    int sum = first + second;
    cout << sum << " ";
    first = second;
    second = sum;

    return fibo(n - 1, first, second);
}

void fiboIterative(int n)
{
    int first = 0;
    int second = 1;

    for (int i = 3; i <= n; i++)
    {
        int sum = first + second;
        cout << sum << " ";

        first = second;
        second = sum;
    }
}

void isSorted(int arr[], int start, int end)
{
    if (start == end - 1)
    {
        cout << "Sorted hai";
        return;
    }

    if (arr[start] > arr[start + 1])
    {
        cout << "Not sorted";
        return;
    }

    isSorted(arr, start + 1, end);
}

void BinarySearch(int arr[], int start, int end, int target)
{
    if (start > end)
        return;

    int mid = start + ((end - start) / 2);

    if (target == arr[mid])
    {
        cout << "Foudn at index: " << mid << endl;
        return;
    }

    else if (arr[mid] < target)
    {
        start = mid + 1;
    }
    else
    {
        end = mid - 1;
    }

    BinarySearch(arr, start, end, target);
}

int mysum(int arr[], int start, int end)
{
    if (start == end - 1)
        return arr[start];

    int val = mysum(arr, start + 1, end);
    int ans = arr[start] + val;
    return ans;
}

int myAtoi(string s)
{
    int sign = 1;
    long long ans = 0;
    int i = 0;

    while (i < s.size())
    {
        if (s[i] == '-')
        {
            sign = -1;
            i = i + 1;
            break;
        }

        if (s[i] == '+')
        {
            i = i + 1;
            break;
        }

        else if (s[i] == ' ')
        {
            i = i + 1;
        }
        else
        {
            break;
        }
    }

    while (i < s.size() && isdigit(s[i]))
    {
        int digit = s[i] - '0';
        ans = (ans * 10) + digit;

        if (sign * ans > INT_MAX)
            return INT_MAX;
        if (sign * ans < INT_MIN)
            return INT_MIN;
        i = i + 1;
    }

    return sign * ans;
}

double myPow(double x, long n)
{
    if (n == 1)
    {
        return x;
    }

    if (n % 2 == 1)
    {
        return 2 * myPow(x, n / 2) * myPow(x, n / 2);
    }

    else if (n % 2 == 0)
    {
        return myPow(x, n / 2) * myPow(x, n / 2);
    }
}

void recurAns(set<string> &result, int a, int b, string ans){
    if(b == ans.size()) return;
    string dupans = ans;
    swap(dupans[a], dupans[b]);

    result.insert(dupans);

    recurAns(result, a, b + 1, dupans);
}

int main()
{
    int n = 3;
    string ans(n, '0');
    // ans[n - 1] = '1';

    int a = 0;
    int b = 0;
    set<string> result;
     for (int i = 0; i < ans.size(); i++) {
         recurAns(result, a, 0, ans);
         ans = string(n, '0');
        ans[n - a - 1] = '1'; 
    }


    vector<string> val(result.begin(), result.end());


    for(int i = 0; i < val.size(); i++){
        cout << val[i] << " ";
    }

    return 0;
}