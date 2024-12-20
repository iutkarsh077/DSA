#include <bits/stdc++.h>
using namespace std;

class ArrayProblem{
    public:

     int maxProduct(vector<int>& nums) {

        if(nums.size() == 1) return nums[0];
        int maxi = 0;
        int prefix = 1;
        int suffix = 1;

        for(int i = 0; i < nums.size(); i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[nums.size() - i - 1];
            maxi = max(maxi, max(prefix, suffix));
        }

        return maxi;
    }

    int reversePairs(vector<int> &nums){

        if(nums.size() == 1) return -1;
        sort(nums.begin(), nums.end());

        if(nums[0] != nums[1]){
            return nums[0];
        }

        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i] != nums[i - 1] && nums[i] != nums[i + 1]){
                return nums[i];
            }
        }

        if(nums[nums.size() - 2] != nums[nums.size() - 1]){
            return nums[nums.size() - 1];
        }

        return -1;
    }
};

int main() {
    ArrayProblem FirstClass;
    vector<int> nums = {2, 4, 3, 5, 1};
    int result = FirstClass.reversePairs(nums);
    cout << result << endl;
    return 0;
}