#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class ArrayProblem
{
public:
    void SubArrayProblem(vector<int> arr, int k)
    {
        map<long long, int> mp;
        long long sum = 0;
        int maxi = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum = sum + arr[i];
            if (sum == k)
            {
                maxi = max(maxi, i + 1);
            }

            int val = sum - k;
            if (mp.find(val) != mp.end())
            {
                int len = i - mp[val];
                maxi = max(len, maxi);
            }

            if (mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }

        cout << maxi;
    }

    
};

int main()
{
    ArrayProblem arr;
    vector<int> arr1 = {-1, 2, -3};
    arr.SubArrayProblem(arr1, -2);
    return 0;
}