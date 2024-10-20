#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> st;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        vector<int> val;
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    val.push_back(nums[i]);
                    val.push_back(nums[j]);
                    val.push_back(nums[k]);
                    sort(val.begin(), val.end());
                    st.insert(val);
                    val.clear();
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());

    return ans;
}

int main()
{
    return 0;
}