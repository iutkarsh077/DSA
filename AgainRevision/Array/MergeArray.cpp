#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void BruteMethode(vector<int> nums1, vector<int> nums2)
{
    int m = 3;
    int n = 3;
    vector<int> result;
    for (int i = 0; i < m; i++)
    {
        result.push_back(nums1[i]);
    }

    for (int i = 0; i < n; i++)
    {
        result.push_back(nums2[i]);
    }

    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    nums1.erase(nums1.begin() + 3, nums1.end());

    for (int i = 0; i < nums2.size(); i++)
    {
        nums1.push_back(nums2[i]);
    }

    sort(nums1.begin(), nums1.end());

    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    return 0;
}