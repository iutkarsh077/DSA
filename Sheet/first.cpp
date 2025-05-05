#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxi = nums[0];
    int sum = 0;

    for(int i = 0; i < nums.size(); i++){
        sum = sum + nums[i];
        maxi = max(sum, maxi);

        if(sum < 0){
            sum = 0;
        }
    }

    return maxi;
}


int maxProfitBrute(vector<int>& prices) {
    int maxi = 0;

    for (int i = 0; i < prices.size() - 1; i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            maxi = max(maxi, prices[j] - prices[i]);
        }
    }

    return maxi;
}

int maxProfit(vector<int>& prices) {
    int mini = INT_MAX;
    int maxi = 0;
    for(int i = 0; i < prices.size(); i++){
        mini = min(mini, prices[i]);
        maxi = max(maxi, prices[i] - mini);
    }

    return maxi;
}

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans(nums.size(), 0);
    int cntPos = 0;
    int cntNeg = 1;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] >= 0){
            ans[cntPos] = nums[i];
            cntPos = cntPos + 2; 
        }

        else{
            ans[cntNeg] = nums[i];
            cntNeg = cntNeg + 2; 
        }
    }

    return ans;
}


vector<int> leaders(vector<int>& arr) {
    vector<int> ans;
    int maxi = -1;
    
    for(int i = arr.size() - 1; i >= 0; i--){
        if(arr[i] >= maxi){
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            sort(nums.begin(), nums.end());
    
            int cnt = 1;
            int maxi = 1;
    
            if(nums.size() == 0){
                return 0;
            }
    
            if(nums.size() == 1){
                return 1;
            }
    
            for(int i = 0; i < nums.size() - 1; i++){
                if(nums[i] + 1 == nums[i + 1]){
                    cnt++;
                    maxi = max(maxi, cnt);
                }
    
                else if(nums[i] == nums[i + 1]) continue;
                else if(nums[i] + 1 != nums[i + 1]){
                    cnt = 1;
                    maxi = max(cnt, maxi);
                }
            }
            return maxi;
        }
    };

     void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i + 1; j < matrix[i].size(); j++){
                if(i == j) continue;
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        return;
    }

    int subarraySumBrute(vector<int>& nums, int k) {
        int maxi = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            int sum  = 0;
            for(int j = i; j < nums.size(); j++){
                sum = sum + nums[j];
                if(sum == k){
                    maxi++;
                }
            }
        }

        if(nums[nums.size() - 1] == k){
            maxi++;
        }

        return maxi;
    }

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;

        int maxi = 0;
        for(auto i = 0; i != nums.size(); i++){
            sum = nums[i] + sum;
            int val =  sum - k;
            maxi += mp[val];
            mp[sum] += 1;
        }

        return maxi;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size(), 0);
        vector<int> cols(matrix[0].size(), 0);

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(rows[i] == 1 || cols[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }

int main(){

}