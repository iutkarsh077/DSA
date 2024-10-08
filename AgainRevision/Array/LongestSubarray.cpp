#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    vector<int> arr = {-1, 2, 3};

    int k = 6;
    int sum = 0;
    int maxi = 0;
    unordered_map<int, int> mp;

    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];

        if(sum == k){
            maxi =  max(maxi, i + 1);
        }

        int rem = sum - k;
        if(mp.find(rem) != mp.end()){
            int len = i - mp[rem];
            maxi = max(maxi, len);
        }

        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }

    cout << "The maximum length is: " << maxi;;

    return 0;
}