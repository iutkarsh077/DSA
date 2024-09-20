#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int k = 3;
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    priority_queue<int, vector<int>, greater<int>> maxHeap;

    int i = 0;
    int size = arr.size();
    while (i < size)
    {
        maxHeap.push(arr[i]);
        i++;
    }
    
    i = 0;
    while(!maxHeap.empty()){
        cout << maxHeap.top() << " ";
        maxHeap.pop();   
    }
    cout << endl;
    cout << "The Kth max element is: " << maxHeap.top();
    return 0;
}