#include <bits/stdc++.h>
using namespace std;

class ArrayProblem
{
public:
    int LongestSubarrayWithZeroBrute(vector<int> arr)
    {
        int maxi = -1;
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            cnt = 0;
            long long sum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                sum = sum + arr[j];
                cnt++;
                if (sum == 0)
                {
                    maxi = max(cnt, maxi);
                }
            }
        }
        return maxi;
    }

    int LongestSubarrayWithZero(vector<int> nums)
    {
        unordered_map<int, int> mp;
        int maxi = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            if (sum == 0)
            {
                maxi = i + 1;
            }

            else
            {
                if (mp.find(sum) != mp.end())
                {
                    maxi = max(maxi, i - mp[sum]);
                }
                else
                {
                    mp[sum] = i;
                }
            }
        }

        return maxi;
    }

     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = nums1.size() - 1;
        bool flag = true;
        for (int i = nums1.size() - 1; i >= 0; i--) {
            if (nums1[i] != 0) {
                flag = false;
                index = i + 1;
                break;
            }
        }

        if(flag == true){
            index = 0;
        }

        
        int second = 0;
        while (second < nums2.size()) {
            nums1[index] = nums2[second];
            index++;
            second++;
        }

        sort(nums1.begin(), nums1.end());
    }

    vector<vector<int>> mergeOld(vector<vector<int>> nums)
    {
        vector<vector<int>> result;
        int i = 0;
        while (i < nums.size() - 1)
        {
            if (nums[i][1] >= nums[i + 1][0])
            {
                result.push_back({nums[i][0], nums[i + 1][1]});
                i = i + 2;
            }
            else
            {
                result.push_back({nums[i][0], nums[i][1]});
                i = i + 1;
            }
        }
        if (i < nums.size())
        {
            result.push_back({nums[i][0], nums[i][1]});
        }
        return result;
    }
};

int main()
{
    ArrayProblem arrP;
    // vector<int> nums = {15, -2, 2, -8, 1, 7, 10, 23};
    // cout << arrP.LongestSubarrayWithZero(nums);
    vector<vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = arrP.mergeOld(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}