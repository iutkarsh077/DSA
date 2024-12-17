#include <bits/stdc++.h>
using namespace std;

class ArrayProblem
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        long long int arrSum = arr[arr.size() - 1];
        int twiceOccured = -1;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                twiceOccured = arr[i];
            }
            arrSum += arr[i];
        }

        int n = arr.size();
        long long int totalSum = (n * (n + 1)) / 2;
        arrSum = arrSum - twiceOccured;
        int ans = totalSum - arrSum;
        return {twiceOccured, ans};
    }
};

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    ArrayProblem a1;
    a1.findTwoElement(arr);

    return 0;
}