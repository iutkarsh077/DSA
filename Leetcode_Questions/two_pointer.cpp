#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void longestSubArrayBrute()
{
    vector<int> arr = {2, 5, 1, 7, 10};
    int k = 14;
    int maxi = -1;
    int maxSum = 0;
    int maxStartIndex = -1;
    int maxEndIndex = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum = sum + arr[j];
            if (sum > k)
            {
                break;
            }
            if (sum > maxSum)
            {
                maxSum = sum;
                maxi = max(maxi, j - i + 1);
                maxStartIndex = i;
                maxEndIndex = j;
            }
        }
    }

    cout << maxi << endl;
    cout << "Start Index is: " << maxStartIndex << endl;
    cout << "End Index is: " << maxEndIndex << endl;
}

void longestSubArray()
{
    vector<int> arr = {2, 5, 1, 10, 10};
    int k = 14;
    int l = 0;
    int r = l;
    int n = arr.size();
    int sum = 0;
    int startIndex = -1;
    int endIndex = -1;
    int maxi = 0;
    while (r < n)
    {
        sum = sum + arr[r];
        while (sum > k)
        {
            sum = sum - arr[l];
            l++;
        }

        maxi = max(maxi, sum);
        r = r + 1;
    }

    cout << maxi;
}

void constantWindow()
{
    vector<int> arr = {-1, 2, 3, 3, 4, 5, -1};
    int k = 4;

    int l = 0;
    int r = k - 1;
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = l; i <= r; i++)
    {
        sum = sum + arr[i];
    }

    maxi = max(maxi, sum);

    while (r < arr.size() - 1)
    {
        sum = sum - arr[l];
        l++;
        r++;
        sum = sum + arr[r];
        maxi = max(sum, maxi);
    }

    cout << maxi;
    return;
}

void maximumPoints()
{
    vector<int> arr = {2, 10, 1, 3, 5, 7};
    int k = 3;
    int n = arr.size();
    int l = n - k;
    int r = l + k - 1;

    int sum = 0;
    int maxi = 0;

    for (int i = l; i <= r; i++)
    {
        sum = sum + arr[i];
    }

    maxi = max(maxi, sum);

    int i = 0;
    while (i < k)
    {
        sum = sum - arr[l];
        r = (r + 1) % n;
        sum = sum + arr[r];
        l++;
        i++;
        maxi = max(sum, maxi);
    }

    cout << maxi;
}

int lengthOfLongestSubstring(string s)
{
    int l = 0;
    int maxi = 0;
    unordered_set<char> str;

    for (int i = 0; i < s.size(); i++)
    {
        while (str.count(s[i]))
        {
            str.erase(s[l]);
            l++;
        }
        str.insert(s[i]);
        maxi = max(maxi, i - l + 1);
    }

    return maxi;
}

void longestOnes()
{
    vector<int> nums = {0, 0, 0, 0};
    int k = 2;

    int l = 0;
    int r = 0;
    int n = nums.size();
    int cnt = 0;
    int maxi = 0;

    while (r < n)
    {
        if (nums[r] == 0)
        {
            cnt++;
        }

        if (cnt <= k)
        {
            maxi = max(maxi, r - l + 1);
        }

        while (cnt > k)
        {
            if (nums[l] == 0)
            {
                cnt--;
            }
            l++;
        }

        r++;
    }

    cout << maxi;
};

void moveNegposQucikSortMethode()
{
    vector<int> arr = {12, 11, 13, 5, 2, 7, 5, 3, -6};

    int pos = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[pos], arr[i]);
            pos++;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void movePosNegTwoPointers()
{
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};

    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        while (left <= right && arr[left] < 0)
        {
            left++;
        }

        while (left <= right && arr[right] > 0)
        {
            right--;
        }

        if (left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    movePosNegTwoPointers();
    return 0;
}