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


    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return { i, j };
                }
            }
        }

        return { -1, -1 };
    }


    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        if(matrix.size() == 0) return ans;

        int top = 0;
        int left = 0;
        int bottom = matrix.size();
        int right = matrix[0].size();

        while(left < right  && top < bottom){
            // Left To Right
            for(int i = left; i < right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            //Top To Bottom
            for(int i = top; i < bottom; i++){
                ans.push_back(matrix[i][right - 1]);
            }
            right--;

            // Right To Left
           if(top < bottom){
             for(int i = right - 1; i >= left; i--){
                ans.push_back(matrix[bottom - 1][i]);
            }
            bottom--;
           }

            // Bottom To Top
           if(left < right){
             for(int i = bottom - 1; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
           }
        }

        return ans;
    }



    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        if(numRows == 1) return ans;

        for(int i = 1; i < numRows; i++){
            vector<int> result;
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    result.push_back(1);
                }

                else{
                    int sum = ans[i - 1][j - 1] + ans[i - 1][j];
                    result.push_back(sum);
                }
            }
            ans.push_back(result);
        }

        return ans;
    }


    vector<int> majorityElementBrute(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++; 
        }

        for(auto i = mp.begin(); i != mp.end(); i++){
            if(i->second > nums.size()/3){
                ans.push_back(i->first);
            }
        }

        return ans;
    }



     vector<vector<int>> threeSumBrute(vector<int>& nums) {
        set<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> result = {nums[i], nums[j], nums[k]};
                        sort(result.begin(), result.end());
                        ans.insert(result);
                    }
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }


    vector<vector<int>> threeSumBetter(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                   ans.insert({nums[i], nums[l], nums[r]});
                    l = l + 1;
                    r = r - 1;
                }

                else if (sum > 0) {
                    r = r - 1;
                }

                else {
                    l = l + 1;
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }


    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;

        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }

            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            ans.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            ans.push_back(nums2[j]);
            j++;
        }

        nums1.clear();
        nums1 = ans;
        return;
    }

int main(){

}