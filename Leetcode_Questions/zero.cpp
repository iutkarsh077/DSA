#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void moveZeroes(vector<int>& nums) {
    if(nums.size() == 0 || nums.size() == 1){
        return;
    }


    int cntZero = 0;
    int i = 0;

   while(i < nums.size()){
        if(nums[i] == 0){
            cntZero++;
            nums.erase(nums.begin() + i);
        }
        else{
            i++;
        }
    }

    for(int i = 0; i < cntZero; i++){
        nums.push_back(0);
    }

    return;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s1;

    for(int i = 0; i < nums1.size(); i++){
        for(int j = 0; j < nums2.size(); j++){
            if(nums1[i] == nums2[j]){
                s1.insert(nums1[i]);
            }
        }
    }


    vector<int> ans;
    for(auto i = s1.begin(); i != s1.end(); i++){
        ans.push_back(*i);
    }
    return ans;
}

int main() {
    return 0;
}