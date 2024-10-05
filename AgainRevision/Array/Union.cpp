#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void BruteMethode(int arr1[], int arr2[])
{
    set<int> s1;
    for (int i = 0; i < 5; i++)
    {
        s1.insert(arr1[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        s1.insert(arr2[i]);
    }

    vector<int> nums;
    for (auto i = s1.begin(); i != s1.end(); i++)
    {
        nums.push_back(*i);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

void BetterMethode(int arr1[], int arr2[])
{
    vector<int> result;

    for (int i = 0; i < 5; i++)
    {
        result.push_back(arr1[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        result.push_back(arr2[i]);
    }

    sort(result.begin(), result.end());

    for (int i = 0; i < result.size() - 1; i++)
    {
        if (result[i] == result[i + 1])
        {
            result.erase(result.begin() + i + 1);
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 6, 7};

    
    return 0;
}