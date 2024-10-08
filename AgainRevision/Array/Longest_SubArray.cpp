#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};

    int maxi = 0;
    int sum = 0;
    int i = 0;
    int j = 0;
    int k = 15;
    while (j < arr.size())
    {
        sum = sum + arr[j];
        if (sum == k)
        {
            int len = j - i + 1;
            maxi = max(maxi, len);
        }

        while(sum > k){
            sum = sum - arr[i];
            i++;
        }
        j++;
    }

    cout << "The max Length fo sub - array is: " << maxi;
    return 0;
}