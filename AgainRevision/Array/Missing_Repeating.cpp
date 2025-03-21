#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;


 vector<int> findTwoElement(vector<int>& arr) {
    vector<int> hash(arr.size() + 1, 0);
    
    for (int i = 0; i < arr.size(); i++) {
        hash[arr[i]]++;
    }
    
    int repeating = 0;
    int missing = 0;
    
    for (int i = 1; i < hash.size(); i++) {
        if (hash[i] == 2) {
            repeating = i;
        }
        if (hash[i] == 0) {
            missing = i;
        }
    }
    
    return { repeating, missing };
}

vector<int> Rev(vector<int>& arr) {
        // code here
        vector<int> hashed(arr.size() + 1, 0);
        
        for(int i = 0; i < arr.size(); i++){
            hashed[arr[i]]++;
        }
        
        int repeating = 0;
        int missing = 0;
        
        for(int i = 0; i < hashed.size(); i++){
            if(hashed[i] == 2){
                repeating = i;
            }
            
            if(hashed[i] == 0){
                missing = i;
            }
        }
        
        return { repeating, missing };
    }

int main() {
    return 0;
}