#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> &arr) {
    int start = 0;
    int end = arr.size() - 1;
    
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start = start + 1;
        end = end - 1;
    }
    
    return;
}

int main(){
    return 0;
}