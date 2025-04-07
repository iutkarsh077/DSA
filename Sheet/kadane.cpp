#include <bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;
    int ans = largest - smallest;
    int mi = 0;
    int ma = 0;
    for(int i = 0; i < n - 1; i++){
        mi = min(smallest, arr[i + 1] + k);
        ma  = max(largest, arr[i] - k);
        
        if(mi < 0) continue;
        
        ans = min(ans, ma - mi);
    }
    
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    int sum = 0;
    int maxi = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + arr[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    cout << maxi;

    
    return 0;
}