#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

void bubbleSort(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        for(int j = i; j < arr.size() - i; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    vector<int> arr = {5, 1, 6, 2, 8, 4};
    bubbleSort(arr);
    print(arr);
    return 0;
}