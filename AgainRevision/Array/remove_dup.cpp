#include <bits/stdc++.h>
using namespace std;

class ArrayProblem
{
public:
    void RemoveDuplicates(vector<int> arr)
    {
        set<int> st;

        for (int i = 0; i < arr.size(); i++)
        {
            st.insert(arr[i]);
        }

        arr.clear();

        for (auto i = st.begin(); i != st.end(); i++)
        {
            arr.push_back(*i);
        }

        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

        return;
    }

    void RotateMeBrute(vector<int> arr, int k)
    {
        vector<int> dup;
        k = k % arr.size();

        int initial = arr.size() - k;

        for (int i = initial; i < arr.size(); i++)
        {
            dup.push_back(arr[i]);
        }

        for (int i = 0; i < initial; i++)
        {
            dup.push_back(arr[i]);
        }

        arr.clear();

        for (int i = 0; i < dup.size(); i++)
        {
            arr.push_back(dup[i]);
        }

        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
    }

    void moveZeroes(vector<int> &nums)
    {
        int cnt = 0;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == 0)
            {
                cnt++;
                nums.erase(nums.begin() + i);
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i < cnt; i++)
        {
            nums.push_back(0);
        }

        return;
    }

    void moveZeroes2(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 1)
        {
            return;
        }

        int i = 0;
        int j = 1;

        while (i < nums.size() && j < nums.size())
        {
            if (nums[j] != 0 && nums[i] == 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }

            else if (nums[j] != 0 && nums[i] != 0 && j > i)
            {
                i++;
            }

            else
            {
                j++;
            }
        }

        return;
    }

    void UnionOfTwoBrute(vector<int> a, vector<int> b)
    {
        set<int> st;

        for (int i = 0; i < a.size(); i++)
        {
            st.insert(a[i]);
        }

        for (int i = 0; i < b.size(); i++)
        {
            st.insert(b[i]);
        }

        vector<int> ans;

        for (auto i = st.begin(); i != st.end(); i++)
        {
            ans.push_back(*i);
        }

        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }

    void UnionOptimal(vector<int> a, vector<int> b)
    {
        vector<int> result;
        result.push_back(-1);

        int first = 0;
        int second = 0;

        while (first < a.size() && second < b.size())
        {
            if (a[first] <= b[second])
            {
                if (result.back() != a[first])
                {
                    result.push_back(a[first]);
                }
                first++;
            }

            else
            {
                if (result.back() != b[second])
                {
                    result.push_back(b[second]);
                }
                second++;
            }
        }

        while (first < a.size())
        {
            if (result.back() != a[first])
            {
                result.push_back(a[first]);
            }
            first++;
        }

        while (second < b.size())
        {
            if (result.back() != b[second])
            {
                result.push_back(b[second]);
            }
            second++;
        }

        result.erase(result.begin());

        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
    }
};

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 6, 7};
    ArrayProblem array1;

    // array1.RotateMeBrute(arr1, 3);
    // array1.UnionOfTwoBrute(arr1, arr2);
    array1.UnionOptimal(arr1, arr2);
    return 0;
}