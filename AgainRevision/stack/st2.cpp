//Make a stack with the help of array

#include <iostream>
#include <string>
using namespace std;

void printStack(int arr[], int top){
    for(int i = top; i >= 0; i--){
        cout << arr[i] << " ";
    }
    return;
}

void getTop(int arr[], int top){
    cout << arr[top] << endl;
}

void removeElementFromStack(int &top){
    top = top - 1;
}

int main() {
    int n;
    cout << "Enter the length of array: ";
    cin >> n;
    cout << endl;

    int *arr = new int[n];
    int top = -1;
    while(top < n - 1){
        int digit;
        cout << "Enter the val: ";
        cin >> digit;
        cout << endl;
        if(digit == -1) break;
        top++;
        arr[top] = digit;
    }
    
    cout << endl;
    removeElementFromStack(top);
    printStack(arr, top);
    cout << endl;
    getTop(arr, top);
    return 0;
}