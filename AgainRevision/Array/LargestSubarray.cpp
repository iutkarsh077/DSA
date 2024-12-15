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
};

int main()
{
    ArrayProblem arrP;
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << arrP.LongestSubarrayWithZero(nums);
    return 0;
}