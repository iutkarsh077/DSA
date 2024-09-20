#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1; // Heap is 1-indexed, so index 0 is unused
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        // Perform up-heap bubbling
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

    void deleteRootElement()
    {
        if (size == 0)
        {
            cout << "Heap is already empty" << endl;
            return;
        }

        swap(arr[1], arr[size]);
        size--;

        int i = 1;
        while (i <= size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int largest = i;

            if (leftIndex <= size && arr[leftIndex] > arr[largest])
            {
                largest = leftIndex;
            }

            if (rightIndex <= size && arr[rightIndex] > arr[largest])
            {
                largest = rightIndex;
            }

            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                break;
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
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftIndex = 2 * i;
    int rightIndex = 2 * i + 1;

    if (leftIndex <= n && arr[leftIndex] > arr[largest])
    {
        largest = leftIndex;
    }

    if (rightIndex <= n && arr[rightIndex] > arr[largest])
    {
        largest = rightIndex;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    // heap h;
    // h.insert(60);
    // h.insert(50);
    // h.insert(40);
    // h.insert(30);
    // h.insert(20);

    // h.print(); // Output: 60 50 40 30 20
    // h.deleteRootElement();
    // h.print(); // Output: 50 30 40 20 (after deleting the root)

    int arr[] = {-1, 3, 1, 5, 7, 8, 9, 6};

    int n = (sizeof(arr) / sizeof(arr[0])) - 1;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Heapify array is: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
