#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int maxOnes = 0;
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
        }
        else
        {
            maxOnes = max(maxOnes, cnt);
            cnt = 0;
        }
    }

    maxOnes = max(maxOnes, cnt);
    cout << "Maximum 1 in the array is: " << maxOnes;
    return 0;
}