#include <bits/stdc++.h>
using namespace std;

int findFloorBrute(vector<int> &arr, int k)
{
    int floorVal = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= k)
        {
            floorVal = i;
        }
        else
        {
            break;
        }
    }

    return floorVal;
}

int findFloor(vector<int> &arr, int k)
{
    int s = 0;
    int e = arr.size() - 1;
    int index = -1;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (arr[mid] <= k)
        {
            index = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return index;
}

vector<int> getFloorAndCeil(int k, vector<int> &arr)
{
    // code here
    sort(arr.begin(), arr.end());
    int floorVal = -1;
    int ceilVal = -1;
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (arr[mid] <= k)
        {
            floorVal = arr[mid];
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }
    }

    s = 0;
    e = arr.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (arr[mid] >= k)
        {
            ceilVal = arr[mid];
            e = mid - 1;
        }

        else
        {
            s = mid + 1;
        }
    }

    return {floorVal, ceilVal};
}

int searchInsert(vector<int> &nums, int target)
{
    int index = 0;

    if (nums.size() == 0)
    {
        return 0;
    }

    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
        {
            return mid;
        }

        else if (nums[mid] < target)
        {
            index = mid + 1;
            s = mid + 1;
        }
        else
        {
            index = mid;
            e = mid - 1;
        }
    }

    return index;
}

vector<int> searchRange(vector<int> &nums, int target)
{

    if (nums.size() == 0)
    {
        return {-1, -1};
    }
    auto floor = lower_bound(nums.begin(), nums.end(), target);
    auto ceil = upper_bound(nums.begin(), nums.end(), target);

    if (floor == nums.end() || *floor != target)
    {
        return {-1, -1};
    }

    int myfloor = -1;
    int myceil = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            myfloor = i;
            break;
        }
    }

    for (int i = myfloor; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            myceil = i;
        }
    }

    return {myfloor, myceil};
}

 vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return { -1, -1 };
        }

        int s = 0;
        int e = nums.size() - 1;
        int floorVal = -1;
        while(s <= e){
            int mid =  s + ((e - s)/2);

            if(nums[mid] == target){
                floorVal = mid;
                e = mid - 1;
            }

            else if(nums[mid] < target){
                s = mid + 1;
            }

            else{
                e = mid - 1;
            }
        }

        if(floorVal == -1){
            return { -1, -1 };
        }

        int ceilVal = -1;
        for(int i = floorVal; i < nums.size(); i++){
            if(nums[i] == target){
                ceilVal = i;
            }
        }

        return {floorVal, ceilVal};
    }


int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    auto floor = lower_bound(nums.begin(), nums.end(), 11);
    auto ceil = upper_bound(nums.begin(), nums.end(), 11);

    cout << "Floor is: " << *floor << endl;
    cout << "Ceil is: " << *ceil << endl;
    return 0;
}