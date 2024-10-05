#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int nonZero = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[nonZero] = nums[i];
            nonZero++;
        }
    }

    for (int i = nonZero; i < n; i++)
    {
        nums[i] = 0;
    }
}

int main()
{
    return 0;
}