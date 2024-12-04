#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class ArrayProblem
{
public:
    void rearrangeArrayBrute(vector<int> nums)
    {
        vector<int> arr(nums.size(), 0);
        int pos = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0){
                arr[pos] = nums[i];
                pos = pos + 2;
            }
        }

        int neg = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0){
                arr[neg] = nums[i];
                neg = neg + 2;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    }

     vector<int> rearrangeArrayBetter(vector<int>& nums) {
        vector<int> arr(nums.size(), 0);
        int pos = 0;
        int neg = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0){
                arr[pos] = nums[i];
                pos = pos + 2;
            }

            if(nums[i] < 0){
                arr[neg] = nums[i];
                neg = neg + 2;
            }
        }

        return arr;
    }

    
};

int main()
{
    ArrayProblem arr;
    vector<int> nums = {-1, 1};
    arr.rearrangeArrayBrute(nums);
    return 0;
}