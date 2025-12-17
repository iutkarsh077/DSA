#include <bits/stdc++.h>
using namespace std;

void powBrute(double x, int n)
{
    double ans = 1.0;
    long long dup = n;
    if (n < 0)
    {
        dup = -1 * n;
    }
    for (int i = 0; i < dup; i++)
    {
        ans = ans * x;
    }

    if (n < 0)
    {
        ans = 1 / ans;
    }

    cout << ans << endl;
}

int facto(int n)
{
    if (n == 1)
        return 1;

    return n * facto(n - 1);
}

int powerofTwo(int n)
{
    if (n == 0)
        return 1;

    return 2 * powerofTwo(n - 1);
}

void counting(int n)
{
    if (n == 0)
        return;

    counting(n - 1);
    cout << n << endl;
}

void sortArray(int i, int n, vector<int> &arr, int j)
{
    if (j >= n - i - 1)
        return;

    if (arr[j] > arr[j + 1])
    {
        swap(arr[j], arr[j + 1]);
    }

    sortArray(i, n, arr, j + 1);
}

void sortArrayMain()
{
    vector<int> arr = {3, 2, 1};

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sortArray(i, n, arr, 0);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // powBrute(2.10000, 3);
    // long long ans = powerofTwo(10);
    // cout << endl << ans;
    // counting(10);
    sortArrayMain();
    return 0;
}