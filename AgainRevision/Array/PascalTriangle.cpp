#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> nums;

    nums.push_back({1});
    int numRows = 5;
    for (int i = 1; i < numRows; i++)
    {
        vector<int> rows(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            rows[j] = nums[i - 1][j - 1] + nums[i - 1][j];
        }
        nums.push_back(rows);
    }
    return 0;
}