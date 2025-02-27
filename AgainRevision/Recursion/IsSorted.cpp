#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr, int i){
    if(i >= arr.size() - 1){
        return true;
    }

    if (arr[i] > arr[i + 1]) {
        return false;
    }

    return isSorted(arr, i + 1);
}

int main(){
    vector<int> arr = {2, 5, 6, 8, 9, 11, 13, 16};
     bool result = isSorted(arr, 0);
     cout << result << endl;
    return 0;
}