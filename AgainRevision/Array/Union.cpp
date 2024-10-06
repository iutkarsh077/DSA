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

    for (int i = 0; i < 7; i++)
    {
        result.push_back(arr2[i]);
    }

    sort(result.begin(), result.end());

    int i = 0;
    while (i < result.size() - 1)
    {
        if (result[i] == result[i + 1])
        {
            result.erase(result.begin() + i + 1);
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}

void OptimalApproach(int arr1[], int arr2[], int n, int m)
{
    int first = 0;
    int second = 0;

    vector<int> result;

    // Merge and eliminate duplicates
    while (first < n && second < m)
    {
        // If arr1 element is smaller or equal, add to result if not already present
        if (arr1[first] <= arr2[second])
        {
            if (result.empty() || result.back() != arr1[first])
            {
                result.push_back(arr1[first]);
            }
            first++;
            // Skip duplicate elements in both arrays
            if (arr1[first - 1] == arr2[second])
            {
                second++;
            }
        }
        // If arr2 element is smaller, add to result if not already present
        else
        {
            if (result.empty() || result.back() != arr2[second])
            {
                result.push_back(arr2[second]);
            }
            second++;
        }
    }

    // Handle remaining elements in arr1
    while (first < n)
    {
        if (result.empty() || result.back() != arr1[first])
        {
            result.push_back(arr1[first]);
        }
        first++;
    }

    // Handle remaining elements in arr2
    while (second < m)
    {
        if (result.empty() || result.back() != arr2[second])
        {
            result.push_back(arr2[second]);
        }
        second++;
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

void OptimalApproachRev(int arr1[], int arr2[], int m, int n)
{
    int first = 0;
    int second = 0;

    vector<int> result;

    while (first < m && second < n)
    {
        if (arr1[first] <= arr2[second])
        {
            if (result.empty() || result.back() != arr1[first])
            {
                result.push_back(arr1[first]);
            }
            first++;

            if (arr1[first - 1] == arr2[second])
            {
                second++;
            }
        }

        else
        {
            if (result.empty() || result.back() != arr2[second])
            {
                result.push_back(arr2[second]);
            }
            second++;
        }
    }

    while (first < m)
    {
        if (result.empty() || result.back() != arr1[first])
        {
            result.push_back(arr1[first]);
        }
        first++;
    }

    while (second < n)
    {
        if (result.empty() || result.back() != arr2[second])
        {
            result.push_back(arr2[second]);
        }
        second++;
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {1, 1, 1, 1, 1};
    int arr2[] = {2, 3, 5, 5, 5, 6, 7};
    BetterMethode(arr1, arr2);
    cout << endl;
    OptimalApproach(arr1, arr2, 5, 7);
    cout << endl;
    OptimalApproachRev(arr1, arr2, 5, 7);

    return 0;
}