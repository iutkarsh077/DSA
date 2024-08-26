#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxi = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;

        for (int j = i; j < nums.size(); j++)
        {
            sum = sum + nums[j];
            maxi = max(sum, maxi);
        }
        cout << i<< "  " << maxi << endl;
    }
    cout << maxi;
    return 0;
}