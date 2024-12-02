#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class ArrayProblem
{
public:
    void SubArrayProblem(vector<int> arr, int k)
    {
        map<long long, int> mp;
        long long sum = 0;
        int maxi = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum = sum + arr[i];
            if (sum == k)
            {
                maxi = max(maxi, i + 1);
            }

            int val = sum - k;
            if (mp.find(val) != mp.end())
            {
                int len = i - mp[val];
                maxi = max(len, maxi);
            }

            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }

        cout << maxi;
    }

    void sortColors(vector<int> &nums)
    {
        int zero = 0;
        int one = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zero++;
            }

            else if (nums[i] == 1)
            {
                one++;
            }
        }

        int two = nums.size() - (one + zero);
        nums.clear();
        while (one > 0 || two > 0 || zero > 0)
        {
            if (zero > 0)
            {
                nums.push_back(0);
                zero--;
            }

            else if (one > 0)
            {
                nums.push_back(1);
                one--;
            }

            else
            {
                nums.push_back(2);
                two--;
            }
        }

        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << " ";
        }
        return;
    }
};

int main()
{
    ArrayProblem arr;
    vector<int> arr1 = {2, 0, 2, 1, 1, 0};
    // arr.SubArrayProblem(arr1, -2);
    arr.sortColors(arr1);
    return 0;
}