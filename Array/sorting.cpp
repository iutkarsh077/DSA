#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selectionSort()
{
    vector<int> nums;
    nums = {-4, -1, -2, -6, -74, -6, -1, -87, -56, -43};

    for (int i = 0; i < nums.size(); i++)
    {
        int mini = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if(nums[mini] > nums[j]){
                mini = j;
            }
        }
        swap(nums[mini], nums[i]);
    }

    for (int i = 0; i < nums.size(); i++)
    {
       cout << nums[i] << " ";
    }
}

void bubbleSort(){
    vector<int> nums;
    nums = {-4, -1, -2, -6, -74, -6, -1, -87, -56, -43};

    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums.size() - i - 1; j++){
            if(nums[j] > nums[j + 1]){
                swap(nums[j], nums[j + 1]);
            }
        }
    }

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}


void insertionSort(){
    vector<int> nums;
    nums = {4, 1, 2, -6, -74, -6, -1, -87, -56, -43};

    int i = 1;

    while(i < nums.size()){
        int j = i - 1;
        int temp;
        for(; j >= 0; j--){
            if(nums[i] < nums[j]){
                temp = nums[j];
            }
            else{
                break;
            }
        }
        nums[j + 1] = temp;
        i++;
    }

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}

int main()
{
    insertionSort();
    return 0;
}