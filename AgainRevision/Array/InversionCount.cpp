#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int inversionCountBrute(vector<int> &arr)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}


#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int cnt = 0;
void merge(vector<int> &arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += mid - left + 1;
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + ((high - low) / 2);
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    vector<int> arr = {1};
    int i = 0;

    mergeSort(arr, 0, arr.size() - 1);

    while (i < arr.size())
    {
        cout << arr[i] << " ";
        i++;
    }

    cout << endl;

    cout << "The count is " << cnt;
    return 0;
}


int main()
{
    vector<int> arr = {2, 4, 1, 3, 5};
    inversionCountBrute(arr);
    return 0;
}