#include <bits/stdc++.h>
using namespace std;

void BruteMethode(vector<int> nums, int target)
{
    int first = -1;
    int last = -1;
    int flagForFirst = false;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target && flagForFirst == false)
        {
            first = i;
            flagForFirst = true;
        }

        if (nums[i] == target)
        {
            last = i;
        }
    }

    cout << "First Index is: " << first << endl;
    cout << "Last Index is: " << last;
}

int main()
{
    vector<int> nums = {};
    int target = 8;

    int first = -1;
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        if (nums[mid] == target)
        {
            first = mid;
            e = mid - 1;
        }

        else if (nums[mid] < target)
        {
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }
    }

    s = first;
    e = nums.size() - 1;
    int last = -1;

    while (s <= e)
    {
        int mid = s + ((e - s) / 2);

        if (nums[mid] == target)
        {
            s = mid + 1;
            last = mid;
        }

        else if (nums[mid] < target)
        {
            s = mid + 1;
        }

        else
        {
           e =  mid - 1;
        }
    }

    cout << "First Index is: " << first << endl;
    cout << "Last Index is: " << last;
    return 0;
}