#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void largestElement()
{
    vector<int> nums;
    nums = {3, 1, 5, 4, 2, 7, 81, 5, 9, 5, 0};
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
    }

    cout << "Largest element is: " << maxi;
}

void secondLargestElement()
{
    vector<int> nums;
    nums = {3, 1, 5, 4, 2, 7, 81, 5, 9, 5, 0};
    int maxi = INT_MIN;
    int maxiIndex = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= maxi)
        {
            maxi = nums[i];
            maxiIndex = i;
        }
    }

    nums[maxiIndex] = INT_MIN;
    int secMaxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        secMaxi = max(secMaxi, nums[i]);
    }

    cout << "second largest element is: " << secMaxi;
}

bool check(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return true;

    int cnt = 0;
    if (nums[0] < nums[n - 1])
        cnt++;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            cnt++;
        }
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
}

void rotaeByOnePlace()
{
    vector<int> nums;
    nums = {1, 2, 3, 4, 5};

    int first = nums[0];
    if (nums.size() == 1)
        return;

    for (int i = 1; i < nums.size(); i++)
    {
        nums[i - 1] = nums[i];
    }

    nums[nums.size() - 1] = first;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

void moveZeroes()
{
    vector<int> nums = {0};

    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

void LinearSearch()
{
    vector<int> nums;
    nums = {3, 1, 5, 4, 2, 7, 81, 5, 9, 5, 0};
    int target = 5;

    for (int i = 0; i < nums.size(); i++)
    {
        if (target == nums[i])
        {
            cout << i;
            break;
        }
    }
}

void FindTheUnion()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    vector<int> ans;
    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < arr1.size())
    {
        if (ans.size() >= 1 && ans.back() != arr1[i])
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while (j < arr2.size())
    {
        if (ans.size() >= 1 && ans.back() != arr2[j])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end());

        if(nums[0] != nums[1]) return nums[0];

        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i] != nums[i - 1] && nums[i] != nums[i + 1]){
                return nums[i];
            }
        }

        if(nums[nums.size() - 1] != nums[nums.size() - 2]){
            return nums[nums.size() - 1];
        }

        return -1;
    }

int main()
{
    FindTheUnion();
    return 0;
}
