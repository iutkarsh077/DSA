#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int largestElement(vector<int> &nums)
{
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
    }

    return maxi;
}

int findKthLargestBrute(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

int findKthLargest(vector<int> &nums, int k)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    int cnt = 0;
    for (auto i = mp.rbegin(); i != mp.rend(); i++)
    {
        cnt = cnt + i->second;
        if (cnt >= k)
            return i->first;
    }

    return -1;
}

bool check(vector<int> &nums)
{
    int cnt = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            cnt++;
        }
    }

    if (nums[0] < nums[nums.size() - 1])
    {
        cnt++;
    }

    if (cnt <= 1)
        return true;

    return false;
}

void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    return;
}

void moveZeroesBrute(vector<int> &nums)
{
    vector<int> dup;
    int zeroCnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            dup.push_back(nums[i]);
        }
        else
        {
            zeroCnt++;
        }
    }

    for (int i = 0; i < zeroCnt; i++)
    {
        dup.push_back(0);
    }

    nums.clear();
    nums = dup;

    return;
}

void moveZeroesBetter(vector<int> &nums)
{
    int zeroCnt = 0;
    int tracker = 0;
    while (tracker < nums.size())
    {
        if (nums[tracker] == 0)
        {
            zeroCnt++;
            nums.erase(nums.begin() + tracker);
        }
        else
        {
            tracker++;
        }
    }

    for (int i = 0; i < zeroCnt; i++)
    {
        nums.push_back(0);
    }

    return;
}

void moveZeroes(vector<int> &nums)
{
    if (nums.size() == 0 || nums.size() == 1)
        return;

    int i = 0;
    int j = 1;

    while (i < nums.size() && j < nums.size())
    {
        if (nums[j] != 0 && nums[i] == 0)
        {
            swap(nums[i], nums[j]);
            i = i + 1;
        }

        else if (nums[j] != 0 && nums[i] != 0 && j > i)
        {
            i = i + 1;
        }

        else
        {
            j = j + 1;
        }
    }

    return;
}

vector<int> findUnionBrute(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    for (int i = 0; i < a.size(); i++)
    {
        ans.push_back(a[i]);
    }

    for (int i = 0; i < b.size(); i++)
    {
        ans.push_back(b[i]);
    }

    sort(ans.begin(), ans.end());

    int i = 0;
    while (i < ans.size() - 1)
    {
        if (ans[i] == ans[i + 1])
        {
            ans.erase(ans.begin() + i);
        }
        else
        {
            i++;
        }
    }

    return ans;
}

int missingNumber(vector<int> &nums)
{
    int arrSum = 0;
    int n = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
        arrSum += nums[i];
    }

    int totalSum = (n * (n + 1)) / 2;
    return totalSum - arrSum;
}

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int totalCnt = 0;
    int maxCnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            totalCnt++;
            maxCnt = max(maxCnt, totalCnt);
        }
        else
        {
            totalCnt = 0;
        }
    }

    return maxCnt;
}

int singleNumber(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    sort(nums.begin(), nums.end());

    if (nums[0] != nums[1])
    {
        return nums[0];
    }

    for (int i = 0; i < nums.size() - 1; i = i + 2)
    {
        if (nums[i] != nums[i + 1])
        {
            return nums[i];
        }
    }

    if (nums[nums.size() - 1] != nums[nums.size() - 2])
    {
        return nums[nums.size() - 1];
    }

    return -1;
}

void LongestSubarr(vector<int> arr){
    int maxi = 0;
    int sum = 0;

    for(int i = 0; i < arr.size(); i++){
        sum = sum + arr[i];
        maxi = max(maxi, sum);

        if(sum < 0){
            sum = 0;
        }
    }

    cout << "Maximum subarray is: " << maxi;
    cout << endl;
}

int main()
{
    vector<int> arr = {3, 1, 7, 6, 8, -9, 3, 2};
    LongestSubarr(arr);
    return 0;
}