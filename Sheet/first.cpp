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

int main(){

}