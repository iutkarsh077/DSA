#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class MaxHeap
{
public:
    int arr[100];
    int size;

    MaxHeap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void Print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    MaxHeap maxi;
    maxi.insert(60);
    maxi.insert(50);
    maxi.insert(30);
    maxi.insert(20);
    maxi.insert(40);
    maxi.insert(70);
    maxi.Print();
    return 0;
}