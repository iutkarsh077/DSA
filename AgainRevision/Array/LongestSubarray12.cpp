#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int maxLenBrute(vector<int>& arr, int n) {
        // Your code here
        int maxLength = INT_MIN;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += arr[j];
                cnt++;
                if(sum == 0){
                    maxLength = max(cnt, maxLength);
                }
                
            }
        }
        
        return maxLength;
    }

int main() {
    return 0;
}