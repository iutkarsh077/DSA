#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    set<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    result.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans;
    for(const auto& triplet : result){
        ans.push_back(triplet);
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}