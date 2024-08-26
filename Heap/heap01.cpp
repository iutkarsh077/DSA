#include <bits/stdc++.h>
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

    void insert(int data)
    {
        size += 1;
        int index = size;
        arr[index] = data;

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

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteNode()
    {
        if (size == 0)
        {
            cout << "No Element to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftNode = 2 * i;
            int rightNode = 2 * i + 1;

            if (leftNode < size && arr[i] < arr[leftNode])
            {
                swap(arr[i], arr[leftNode]);
                i = leftNode;
            }
            else if (rightNode < size && arr[i] < arr[rightNode])
            {
                swap(arr[i], arr[rightNode]);
                i = rightNode;
            }
            else
            {
                return;
            }
        }
    }
};

int main()
{
    MaxHeap h;
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.insert(89);
    h.print();
    h.deleteNode();
    h.print();

    return 0;
}