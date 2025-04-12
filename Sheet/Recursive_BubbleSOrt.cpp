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

void InsertMe(vector<int> &arr, int i){
    if(i == arr.size()) return;

    int temp = arr[i];
    int j;
    for(j = i - 1; j >= 0; j--){
        if(arr[j] >temp){
            arr[j + 1] = arr[j];
        }
        else{
            break;
        }
    }

    arr[j + 1] = temp;
    i = i + 1;
    InsertMe(arr, i);
}


int main(){
    vector<int> arr = {2, 3, 1, 4, 8, 4 ,3, 5, 3, 2, 1, 7, 6, 5, 4, 89, 9, 76 ,5 , 43, 8, 1 ,2, 3, 0, 8, 7, 6, 4, 9, 32, 75, 3123, 76895, 43211234, 87278};
    InsertMe(arr, 1);
    int i = 0;
    while(i < arr.size()){
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}