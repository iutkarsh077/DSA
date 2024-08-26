#include <bits/stdc++.h>
using namespace std;

void mySubset(vector<vector<int>> &ans, vector<int> output, int index, vector<int> nums)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    mySubset(ans, output, index + 1, nums);

    output.push_back(nums[index]);
    mySubset(ans, output, index + 1, nums);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> output;

    int index = 0;
    mySubset(ans, output, index, nums);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << '{';
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout  <<  ans[i][j] << " ";
        }
        cout << '}';
    }
    return 0;
}