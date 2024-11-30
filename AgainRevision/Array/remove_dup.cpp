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
};

int main()
{
    vector<int> arr = {-1};
    ArrayProblem array1;
    array1.RotateMeBrute(arr, 3);
    return 0;
}