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
            if (nums[i] > 0)
            {
                arr[pos] = nums[i];
                pos = pos + 2;
            }
        }

        int neg = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                arr[neg] = nums[i];
                neg = neg + 2;
            }
        }

        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    }

    vector<int> rearrangeArrayBetter(vector<int> &nums)
    {
        vector<int> arr(nums.size(), 0);
        int pos = 0;
        int neg = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                arr[pos] = nums[i];
                pos = pos + 2;
            }

            if (nums[i] < 0)
            {
                arr[neg] = nums[i];
                neg = neg + 2;
            }
        }

        return arr;
    }

    void nextPermutation(vector<int> nums){
        int flag = true;

        for(int i = nums.size() - 1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                swap(nums[i], nums[i - 1]);
                flag = false;
                break;
            }
        }

        if(flag == true){
            swap(nums[0], nums[nums.size() - 1]);
        }

        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << " ";
        } 
    }
};

int main()
{
    ArrayProblem arr;
    vector<int> nums = {3, 2, 8, 6};
    // arr.rearrangeArrayBrute(nums);
    arr.nextPermutation(nums);
    return 0;
}