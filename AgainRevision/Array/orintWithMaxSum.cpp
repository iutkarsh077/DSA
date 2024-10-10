#include <bits/stdc++.h>
using namespace std;

void printWithMaxSum(vector<int> nums)
{
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int m = i + 1; m < nums.size(); m++)
        {
            int smallest = INT_MAX;
            int secondSmallest = INT_MAX;

            for (int j = i; j <= m; j++)
            {
                if (nums[j] < smallest)
                {
                    secondSmallest = smallest;
                    smallest = nums[j];
                }
                else if (nums[j] < secondSmallest && nums[j] != smallest)
                {
                    secondSmallest = nums[j];
                }
            }

            if (secondSmallest != INT_MAX)
            {
                maxi = max(maxi, smallest + secondSmallest);
            }
        }
    }

    cout << "The max sum of two distinct numbers is: " << maxi << endl;
}

int OptimalApproach(vector<int> &a)
{
    int n = a.size();
    int ans = a[0] + a[1];
    for (int i = 1; i < n - 1; i++)
    {
        ans = max(ans, a[i] + a[i + 1]);
    }
    return ans;
}
int main()
{
    vector<int> nums = {5, 4, 3, 1, 6};
    int result = OptimalApproach(nums);
    cout << result;
    return 0;
}