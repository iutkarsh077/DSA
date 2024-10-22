#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int maxLenBrute(vector<int> &arr, int n)
{
    // Your code here
    int maxLength = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            cnt++;
            if (sum == 0)
            {
                maxLength = max(cnt, maxLength);
            }
        }
    }

    return maxLength;
}

int Optimal(vector<int>& arr, int n) {
        // Your code here
        int maxi = 0;
        int sum = 0;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            sum = sum + arr[i];
            if(sum == 0){
                maxi = i + 1;
            }
            
            else{
                if(mp.find(sum) != mp.end()){
                    maxi = max(maxi, i - mp[sum]);
                }
                else{
                    mp[sum] = i;
                }
            }
        }
        
        return maxi;
    }



 int Optimal(vector<int>& arr, int n) {
        // Your code here
        int maxi = 0;
        int sum = 0;
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            sum = sum + arr[i];
            if(sum == 0){
                maxi = i + 1;
            }
            
            else{
                if(mp.find(sum) != mp.end()){
                    maxi = max(maxi, i - mp[sum]);
                }
                else{
                    mp[sum] = i;
                }
            }
        }
        
        return maxi;
    }

int main()
{
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    return 0;
}