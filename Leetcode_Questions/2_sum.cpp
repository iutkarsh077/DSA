#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nums[] = {3, 2, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int copiedNums[n];
    copy(nums, nums + n, copiedNums);
    sort(nums, nums + n);
    int target = 6;
    int flag = false;
    int first = -1;
    int second = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] < target)
        {
            int s = 0;
            int e = i;
            while (s <= e)
            {
                int mid = (e - s) / 2;
                if (nums[i] + nums[mid] == target)
                {
                    cout << "The value are: " << mid << " " << i << endl;
                    first = nums[mid];
                    second = nums[i];
                    flag = true;
                    break;
                }
                else if (nums[i] + nums[mid] > target)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
        }
        if (flag == true)
        {
            break;
        }
    }

    if(first != -1 && second != -1){
        for(int i = 0; i < n; i++){
            if(first == copiedNums[i]){
                cout << "The first value is: " << first << endl;
            }
            if(second == copiedNums[i]){
                cout << "The second value is: " << second << endl;
            }
        }
    }
    cout << -1;
    return 0;
}