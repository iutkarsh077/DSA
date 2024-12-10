#include <bits/stdc++.h>
using namespace std;

class ArrayProblem
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        result.push_back({1});

        if (numRows == 1)
        {
            return result;
        }

        for (int i = 1; i < numRows; i++)
        {
            vector<int> val;
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                {
                    val.push_back(1);
                }
                else
                {
                    int digit = result[i - 1][j - 1] + result[i - 1][j];
                    val.push_back(digit);
                }
            }
            result.push_back(val);
        }
        return result;
    }

    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        vector<int> arr;

        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            if (i->second > nums.size() / 3)
            {
                arr.push_back(i->first);
            }
        }

        return arr;
    }
};

int main()
{
    ArrayProblem arr;
    // vector<vector<int>> result = arr.generate(5);
    vector<int> nums = {3, 2, 3};
    vector<int> result = arr.majorityElement(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}