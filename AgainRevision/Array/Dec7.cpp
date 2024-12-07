#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class ArrayProblem
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int cnt = 1;
        int maxi = 1;

        if (nums.size() == 0)
        {
            return 0;
        }

        if (nums.size() == 1)
        {
            return 1;
        }

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] + 1 == nums[i + 1])
            {
                cnt++;
                maxi = max(maxi, cnt);
            }

            else if (nums[i] == nums[i + 1])
                continue;
            else if (nums[i] + 1 != nums[i + 1])
            {
                cnt = 1;
                maxi = max(cnt, maxi);
            }
        }
        return maxi;
    }

    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<int> rows(matrix.size(), 0);
        vector<int> col(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (rows[i] == 1 || col[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main()
{
    ArrayProblem arr;
    vector<int> nums = {0};
    int result = arr.longestConsecutive(nums);
    cout << result;
    return 0;
}