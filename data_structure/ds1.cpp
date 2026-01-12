#include <bits/stdc++.h>
using namespace std;

void RightHighest()
{
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    int n = nums.size();
    vector<int> result(n, 0);
    int maxi = -1;

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = maxi;
        if (nums[i] > maxi)
        {
            maxi = nums[i];
        }
        result[i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}

void FlipTheArray()
{
    vector<int> arr = {4, 5, 1, 2, 3};

    int s = 0;
    int e = arr.size() - 1;

    while (s < e)
    {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

vector<int> asteroidCollision(vector<int> &nums)
{
    int i = 0;
    stack<int> st;
    int n = nums.size();
    while (i < n)
    {
        bool collision = false;
        while (!st.empty() && nums[i] < 0 && st.top() > 0)
        {
            int top = st.top();

            if (abs(nums[i]) > top)
            {
                st.pop();
            }

            else if (abs(nums[i]) < top)
            {
                collision = true;
                i++;
                break;
            }

            else
            {
                collision = true;
                st.pop();
                i++;
                break;
            }
        }

        if (!collision)
        {
            st.push(nums[i]);
            i++;
        }
    }

    vector<int> result;

    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int sumOfMinimumsInSubarrays(vector<int> &arr)
{
    static const long long MOD = 1000000007;
    long long int ans = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int mini = INT_MAX;
        for (int j = i; j < arr.size(); j++)
        {
            mini = min(mini, arr[j]);
            ans = ans + mini;
        }
    }

    int result = ans % MOD;
    return result;
}

int main()
{
    vector<int> nums = {11, 81, 94, 43, 3};

    int ans = sumOfMinimumsInSubarrays(nums);
    cout << ans << endl;

    return 0;
}