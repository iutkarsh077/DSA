#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

/*class MaxHeap
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
*/

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

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MaxHeap heap;
    heap.insert(60);
    heap.insert(50);
    heap.insert(30);
    heap.insert(20);
    heap.insert(40);
    heap.insert(55);
    heap.print();
    return 0;
}