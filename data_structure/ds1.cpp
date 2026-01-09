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
        result[i] = temp;
    }


    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
}

void FlipTheArray(){
    vector<int> arr = {4, 5, 1, 2, 3};

    int s = 0;
    int e = arr.size() - 1;

    while(s < e){
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

int main(){
    FlipTheArray();
    return 0;
}