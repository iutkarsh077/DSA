#include <bits/stdc++.h>
using namespace std;

class ArrayProblem
{
public:
    int majorityElement(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    cnt++;
                }
            }
            if (cnt > nums.size() / 2)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

int main()
{
    ArrayProblem arr1;
    vector<int> arr = {3, 2, 3};
    cout << arr1.majorityElement(arr);
    return 0;
}