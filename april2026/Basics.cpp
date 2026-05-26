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

void MergeSort(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void Divide(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + ((high - low) / 2);
    Divide(arr, low, mid);
    Divide(arr, mid + 1, high);
    MergeSort(arr, low, mid, high);
}

void RecursiveBubbleSort2(vector<int> &arr, int i, int j)
{
    if (j >= arr.size() - i - 1)
        return;

    if (arr[j] > arr[j + 1])
    {
        swap(arr[j], arr[j + 1]);
    }

    RecursiveBubbleSort2(arr, i, j + 1);
}

void RecursiveBubbleSort1(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int j = 0;
        RecursiveBubbleSort2(arr, i, j);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

vector<vector<int>> generate(int n)
{
    vector<vector<int>> nums;

    for (int i = 0; i < n; i++)
    {
        vector<int> ans(i + 1, 1);
        for (int j = 0; j <= i; j++)
        {
            if (j != 0 && j != i)
            {
                int val = nums[i - 1][j - 1] + nums[i - 1][j];
                ans[j] = val;
            }
        }
        nums.push_back(ans);
    }

    return nums;
}

int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            e = mid - 1;
        else
        {
            s = mid + 1;
        }
    }

    return -1;
}

int lowerBound(vector<int> &arr, int target)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    int ans = n;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (arr[mid] >= target)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

int main()
{
    // NToOne(10);
    // cout << SumNNumber(7, 0);
    // int arr[] = {1, 2, 3, 4, 5, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // ReverserArray(0, n - 1, arr);

    vector<int> arr = {4, 1};
    // int n = arr.size();
    // Divide(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    RecursiveBubbleSort1(arr);
    return 0;
}