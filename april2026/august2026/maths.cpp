#include <bits/stdc++.h>
using namespace std;

int countDigits(int n)
{
    int count = 0;

    if (n == 0)
        return 1;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }

    return count;
}

int reverse(int x)
{
    long long val = 0;
    long long dupN = x;

    if (dupN < 0)
    {
        dupN = dupN * -1;
    }
    while (dupN > 0)
    {
        int digit = dupN % 10;
        val = (val * 10) + digit;
        dupN = dupN / 10;
    }

    if (x < 0)
    {
        val = val * -1;
    }

    if (val < INT_MIN || val > INT_MAX)
    {
        return 0;
    }

    return (int)val;
}

int gcd(int a, int b)
{
    if (a == b)
        return a;
    while (a > 0 && b > 0)
    {
        if (a < b)
        {
            b = b % a;
        }
        else
        {
            a = a % b;
        }
    }

    if (a <= 0)
        return b;
    return a;
}

vector<int> getDivisors(int n)
{
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

bool isPrime(int n)
{

    if (n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool armstrongNumber(int n)
{
    // code here
    int val = 0;
    int dupN = n;

    if (dupN < 0)
    {
        dupN = dupN * -1;
    }

    while (dupN > 0)
    {
        int digit = dupN % 10;
        int cube = pow(digit, 3);
        val = val + cube;
        dupN = dupN / 10;
    }

    return val == n ? true : false;
}

void RecurNTimes(int n)
{
    if (n == 0)
        return;

    cout << "Something" << endl;

    RecurNTimes(n - 1);
}

void OnetoN(int n, int i)
{
    if (i > n)
        return;

    cout << i << endl;

    OnetoN(n, i + 1);
}

int Facto(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * Facto(n - 1);
}

void RevArray(vector<int> &arr, int i)
{
    int n = arr.size();
    if (i == n - i - 1)
        return;

    swap(arr[i], arr[n - i - 1]);

    RevArray(arr, i + 1);
}

bool isPalindrome(string s)
{
    string value = "";

    int i = 0;
    while (i < s.size())
    {
        if (isalnum(s[i]))
        {
            value += tolower(s[i]);
        }
        i++;
    }

    string dupVal = "";

    for (int i = value.size() - 1; i >= 0; i--)
    {
        dupVal += value[i];
    }

    if (dupVal == value)
        return true;

    return false;
}

int fib(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

unordered_map<int, int> FrequencyCount(vector<int> arr)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }

    return mp;
}

void selectionSort()
{
    vector<int> arr = {4, 1, 2, 6, 7, 5, 8, 8};

    for (int i = 0; i < arr.size(); i++)
    {
        int mini = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[mini] > arr[j])
            {
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void insertionSort()
{
    vector<int> arr = {5, 4, 1, 6, 7, 8, 9, 3, 2, 3};

    int i = 0;
    int n = arr.size();

    while (i < n)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            if (temp < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }

        arr[j + 1] = temp;
        i++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void bubbleSort()
{
    vector<int> arr = {4, 1, 2, 6, 7, 5, 8, 8};

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    insertionSort();
    return 0;
}