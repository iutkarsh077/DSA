#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3, 3};
    int target = 6;
    unordered_map<int, int> mp;
   for (int i = 0; i < nums.size(); i++) {
        int rem = target - nums[i];
        
        
        if (mp.find(rem) != mp.end()) {
            
            cout << mp[rem] << " " << i << endl;
            return 0;
        }
        
        mp[nums[i]] = i;
    }
    return 0;
}
