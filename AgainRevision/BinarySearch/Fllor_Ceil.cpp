#include <bits/stdc++.h>
using namespace std;

void BruteMethode(vector<int> nums)
{
    int x = 37;
    sort(nums.begin(), nums.end());
    int floor = -1;
    int ceil = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= x)
        {
            floor = nums[i];
        }

        if (nums[i] >= x)
        {
            ceil = min(ceil, nums[i]);
        }
    }

    cout << "Floor is: " << floor << endl;
    cout << "Ceil is: " << ceil;
}

int main()
{
    vector<int> arr = {5, 6, 8, 9, 6, 5, 5, 6};

    sort(arr.begin(), arr.end());
    int s = 0;
    int e = arr.size() - 1;
    int floor = -1;
    int ceil = INT_MAX;
    int x = 9;
    int flag = false;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (arr[mid] == x)
        {
            floor = arr[mid];
            ceil = arr[mid];
            flag = true;
            break;
        }

        else if (arr[mid] < x)
        {
            floor = arr[mid];
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }
    }

    if (flag == true)
    {
        cout << "Floor is: " << floor << endl;
        cout << "Ceil is: " << ceil;
        return 0;
    }

    s = 0;
    e = arr.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (arr[mid] < x)
        {
            s = mid + 1;
        }

        else
        {
            ceil = arr[mid];
            e = mid - 1;
        }
    }

    cout << "Floor is: " << floor << endl;
    cout << "Ceil is: " << ceil;

    return 0;
}