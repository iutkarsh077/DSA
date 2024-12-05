#include <bits/stdc++.h>
using namespace std;
class ArrayProblem
{
public:
    void nextPermutation(vector<int> nums)
    {
    }

    void getPermutationFirst(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                getPermutationFirst(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    void getPermutationSecond(vector<int> &ds, vector<int> &nums, set<vector<int>> &ans, int freq[])
    {
        if (ds.size() == nums.size())
        {
            ans.insert(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                getPermutationSecond(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
};

void CallPermutaions()
{
    ArrayProblem arr;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()] = {0};
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0;
    arr.getPermutationFirst(ds, nums, ans, freq);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    ArrayProblem arr;
    vector<int> nums = {1, 1, 5};
    set<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()] = {0};
    arr.getPermutationSecond(ds, nums, ans, freq);
    vector<vector<int>> sorted_ans(ans.begin(), ans.end());
    sort(sorted_ans.begin(), sorted_ans.end());

     for (int i = 0; i < sorted_ans.size(); i++)
    {
        for (int j = 0; j < sorted_ans[i].size(); j++)
        {
            cout << sorted_ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}