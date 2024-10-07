#include <bits/stdc++.h>
using namespace std;


 int singleNumber(vector<int>& nums) {
        map<int, int> mp;

        if(nums.size() == 1){
            return nums[0];
        }

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto i = mp.begin(); i != mp.end(); i++){
            if(i->second == 1){
                return i->first;
            }
        }

        return -1;
    }

int main() {
    vector<int> nums = {4, 1, 2 ,1, 2};

    int val = singleNumber(nums);

    cout << "The single number is: " << val;
    return 0;
}