#include <bits/stdc++.h>
using namespace std;

class ArrayProblem
{
public:
    int majorityElementBrute(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    cnt++;
                }
            }
            if (cnt > nums.size() / 2)
            {
                return nums[i];
            }
        }
        return -1;
    }

    int majorityElementBetter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    int majorityElementOptimal(vector<int> &nums)
    {
        int maxElement = nums[0];
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                maxElement = nums[i];
                cnt++;
            }
            else if (maxElement == nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }

        cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxElement == nums[i])
            {
                cnt++;
            }
        }

        if (cnt > nums.size() / 2)
        {
            return maxElement;
        }

        return -1;
    }

    int pairWithMaxSumBrute(vector<int> &arr)
    {
        int maxi = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                vector<int> nums(arr.begin() + i, arr.begin() + j + 1);
                sort(nums.begin(), nums.end());
                int smallest = nums[0];
                int secondSmallest = nums[1];
                maxi = max(maxi, smallest + secondSmallest);
            }
        }

        return maxi;
    }

    int pairWithMaxSumBetter(vector<int> &arr)
    {
     
        int maxi = INT_MIN;
        
    for (int i = 0; i < arr.size() - 1; i++)
    {
        maxi = max(maxi, arr[i] + arr[i + 1]);
    }
    return maxi;
    }

     int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit1 = 0;

        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit1 = max(maxProfit1, prices[i] - minPrice);
        }

        return maxProfit1;
    }
};

int main()
{
    ArrayProblem arr1;
    // vector<int> arr = {3, 2, 3};
    // cout << arr1.majorityElementBrute(arr);
    // vector<int> nums(arr.begin() + 0, arr.begin() + 2);
    // for(int i = 0; i < nums.size(); i++){
    //     cout << nums[i] << " ";
    // }
    vector<int> arr = {4, 3, 1, 5, 6};
    cout << arr1.pairWithMaxSumBetter(arr);
    return 0;
}