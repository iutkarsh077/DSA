#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void sort012(vector<int>& arr) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0){
            zeroCount++;
        }
        else if(arr[i] == 1){
            oneCount++;
        }
        else{
            twoCount++;
        }
    }
    
    arr.clear();
    
    while(zeroCount > 0 || oneCount > 0 || twoCount > 0){
        if(zeroCount > 0){
            arr.push_back(0);
            zeroCount--;
        }
        
        else if(oneCount > 0){
            arr.push_back(1);
            oneCount--;
        }
        
        else{
             arr.push_back(2);
            twoCount--;
        }
    }
}


int getMinDiff(vector<int>& arr, int k) {
    int n = arr.size();
    if (n == 1) return 0;  // If there's only one tower, difference is 0.
    
    // Sort the array to handle elements in order.
    sort(arr.begin(), arr.end());

    // Initialize the result as the difference between the max and min height in the sorted array.
    int result = arr[n - 1] - arr[0];

    // The smallest possible height and largest possible height after adjusting with k
    int smallest = arr[0] + k;
    int largest = arr[n - 1] - k;

    // Traverse through the array to explore the different possibilities
    for (int i = 0; i < n - 1; i++) {
        int minHeight = min(smallest, arr[i + 1] - k);
        int maxHeight = max(largest, arr[i] + k);
        
        // If the new height is negative, skip to avoid invalid cases
        if (minHeight < 0) continue;

        // Update the result with the minimum possible difference
        result = min(result, maxHeight - minHeight);
    }

    return result;
}

void rotate(vector<int> &arr) {
    // code here
    for(int i = 0; i < arr.size() - 1; i++){
        swap(arr[i], arr[arr.size() - 1]);
    }
}


int main() {
    return 0;
}