#include<bits/stdc++.h>
using namespace std;

void RightHighest(){
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    int n = nums.size();
    vector<int> result(n, 0);
    int maxi = -1;

    for(int i = n - 1; i >= 0; i--){
        int temp = maxi;
        if(nums[i] > maxi){
            maxi = nums[i];
        }
        nums[i] = temp;
    }


    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
}

int main(){
    RightHighest();
    return 0;
}