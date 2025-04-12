#include<iostream>
#include<vector>
using namespace std;

void BubbleMe(vector<int> &arr, int i){
    if(i == arr.size() - 1) return;

    for(int j = 0; j < arr.size() - i - 1; j++){
        if(arr[j] > arr[j + 1]){
            swap(arr[j], arr[j + 1]);
        }
    }

    i = i + 1;
    BubbleMe(arr, i);
} 

int main(){
    vector<int> arr = {6, 4, 8, 1, 9, 2,  7, 90785, 675765675};
    BubbleMe(arr, 0);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}