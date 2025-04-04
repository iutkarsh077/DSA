#include<iostream>
#include<vector>
#include<map>
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

void kthSmallest(vector<int> arr, int k){
    map<int, int> mpp;
    for(int i = 0; i < arr.size(); i++){
        mpp[arr[i]] = i;
    }

    int index = 0;
    for(auto i = mpp.begin(); i != mpp.end(); i++){
       if(index == k - 1){
        cout << i->first;
        break;
       }
       else{
        index++;
       }
    }

    cout << endl;
    cout << endl;

    for(auto i = mpp.begin(); i != mpp.end(); i++){
        cout << i->first << " " << i->second << endl;
    }
}

int main(){
    vector<int> arr ={7, 10, 4, 3, 20, 15};
    kthSmallest(arr, 3);
    return 0;
}