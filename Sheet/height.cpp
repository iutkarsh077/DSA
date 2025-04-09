#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int getMinDiff(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;
    int ans = largest - smallest;
    for(int i = 0; i < n - 1; i++){
        int minHeight = min(smallest, arr[i + 1] - k);
        int maxHeight = max(largest, arr[i] + k);
        
        if (minHeight < 0) continue;

        ans = min(ans, maxHeight - minHeight);
    }
    
    return ans;
}

int main() {
    return 0;
}