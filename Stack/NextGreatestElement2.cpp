#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {1,5,3,6,8};
    vector<int> result;
    for(int i = 0; i < nums.size(); i++){
        int target = nums[i];
        bool flag = true;
        for(int j = i; j < nums.size()+ i; j++){
            int k = j % nums.size();
            if(nums[k] > target){
                result.push_back(nums[k]);
                flag = false;
                break;
            }
        }
        if(flag == true){
            result.push_back(-1);
        }
    }
    
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}