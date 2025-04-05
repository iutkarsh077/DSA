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


int main() {
    return 0;
}