#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void largestElement(){
    vector<int> nums;
    nums = {3, 1, 5, 4, 2, 7, 81, 5, 9, 5, 0};
    int maxi = INT_MIN;

    for(int i = 0; i < nums.size(); i++){
        maxi = max(maxi, nums[i]);
    }

    cout << "Largest element is: " << maxi;

}

int main(){
    largestElement();
    return 0;
}
