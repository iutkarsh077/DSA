#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix[0].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int subarraySum(vector<int> &nums, int k)
{
    map<int, int> mp;

    int prefix = 0;
    int cnt = 0;
    mp[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        prefix += nums[i];
        int remove = prefix - k;
        cnt += mp[remove];
        mp[prefix] += 1;
    }
    return cnt;
}

int main()
{
    return 0;
}