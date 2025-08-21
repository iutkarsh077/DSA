#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void countFrequency(){
    vector <int> nums;
    nums = {4, 1, 6, 5, 8, 9, 2, 3, 4, 98, 9, 2, 3, 4, 1};
    unordered_map<int, int> mp;
    
    for(int i = 0; i < nums.size(); i++){
        mp[nums[i]]++;
    }

    for(auto i = mp.begin(); i != mp.end(); i++){
        cout << i->first << " " << i->second << endl;
    }
}

int main()
{
    countFrequency();
    return 0;
}