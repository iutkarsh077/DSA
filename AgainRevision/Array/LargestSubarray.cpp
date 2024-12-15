#include <bits/stdc++.h>
using namespace std;

class ArrayProblem
{
public:
    int LongestSubarrayWithZero(vector<int> arr)
    {
        int maxi = -1;
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            cnt = 0;
            long long sum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                sum = sum + arr[j];
                cnt++;
                if (sum == 0)
                {
                    maxi = max(cnt, maxi);
                }
            }
        }
        return maxi;
    }
};

int main()
{
    ArrayProblem arrP;
    vector<int> nums = {0};
    cout  << arrP.LongestSubarrayWithZero(nums);
    return 0;
}