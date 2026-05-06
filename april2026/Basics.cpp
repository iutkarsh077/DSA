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

int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }

    cout << max(a, b);
}

void allDivisor(int n)
{
    vector<int> nums;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            nums.push_back(i);
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

void CheckPrimeNumber(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << "No, its not a prime number" << endl;
            return;
        }
    }

    cout << "Yes, Its a prime number";
}

void NameNTimes(int n)
{
    if (n == 0)
        return;

    cout << "Utkarsh" << endl;
    NameNTimes(n - 1);
}

void OneToN(int n, int i)
{
    if (i > n)
        return;

    cout << i << endl;
    OneToN(n, i + 1);
}

void NToOne(int n)
{
    if (n == 0)
        return;

    cout << n << endl;
    NToOne(n - 1);
}

int SumNNumber(int n, int sum)
{
    if (n == 0)
        return sum;

    sum = sum + n;
    SumNNumber(n - 1, sum);
}

int Facto(int n, int ans)
{
    if (n == 0)
        return ans;

    ans = ans * n;
    return Facto(n - 1, ans);
}

void ReverserArray(int i, int j, int arr[])
{
    if (i > j)
        return;

    swap(arr[i], arr[j]);
    ReverserArray(i + 1, j - 1, arr);
}

void SelectionSort(vector<int> arr)
{
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
        swap(arr[mini], arr[i]);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void BubbleSort(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (flag == false)
        {
            break;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void InsertionSort(vector<int> arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
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
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // NToOne(10);
    // cout << SumNNumber(7, 0);
    // int arr[] = {1, 2, 3, 4, 5, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // ReverserArray(0, n - 1, arr);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    vector<int> arr = {5, 2, 3, 1, 6, 6, 8, 9, 3};
    InsertionSort(arr);
    return 0;
}