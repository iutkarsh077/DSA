#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void bubbleSort(vector<int> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{
    vector<int> arr = {41, 9, 9, 48, 11, 2, 11, 12, 28, 10, 15, 4, 16, 487};

    for (int i = 1; i < arr.size(); i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j + 1] = temp; 
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}