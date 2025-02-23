#include <bits/stdc++.h>
using namespace std;


int searchValues(vector<int> arr, int k, int s, int e, int ans){
    if(s > e){
        return ans;
    }
    
    int mid = s + ((e - s)/2);
    if(arr[mid] == k){
        ans = mid;
        e = mid - 1;
    }
    
    else if(arr[mid] > k){
        e = mid - 1;
    }
    
    else{
        s = mid + 1;
    }
    
    
    return searchValues(arr, k, s, e, ans);
}

int binarysearch(vector<int> &arr, int k) {
    
    int ans = searchValues(arr, k, 0, arr.size() - 1, -1);
    return ans;
}

int main() {
    return 0;
}