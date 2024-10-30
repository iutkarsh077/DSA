#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1};
    int target = 2;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (target == nums[i])
        {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}