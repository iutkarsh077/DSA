#include <bits/stdc++.h>
using namespace std;

void pairme()
{
    pair<int, pair<int, int>> p = {1, {2, 3}};

    cout << p.second.second;
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second > p2.second)
        return false;
    if (p1.second < p2.second)
        return true;

    if (p1.first > p2.first)
        return true;
    return false;
}

void myset()
{
    set<int, greater<int>> s1 = {4, 1, 3, 2, 5, 6};
    s1.insert(20);
    s1.erase(1);

    for (auto i = s1.begin(); i != s1.end(); i++)
    {
        cout << *(i) << " ";
    }

    cout << endl;
    cout << s1.size() << endl;

    auto it = s1.find(90);

    cout << *it;

    pair<int, int> mp[] = {{2, 3}, {4, 5}, {3, 2}};

    sort(mp, mp + 3, comp);
}

void iter()
{
    vector<int> v = {10, 20, 30, 40};

    v.insert(v.begin(), {1, 2, 3});

    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *(i) << " ";
    }
}

void MergeArray(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;

    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= end)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

void printMe(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void DivideMe(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    DivideMe(arr, start, mid);
    DivideMe(arr, mid + 1, end);
    MergeArray(arr, start, mid, end);
}

int partition(vector<int> &arr, int low, int high)
{
    int left = low;
    int right = high;

    int cnt = 0;
    int i = low;
    while (i <= high)
    {
        if (arr[low] >= arr[i])
        {
            cnt++;
        }
        i++;
    }

    int partitionIndex = cnt + low - 1;

    swap(arr[partitionIndex], arr[low]);

    while (left < partitionIndex && right > partitionIndex)
    {
        while (arr[left] <= arr[partitionIndex])
        {
            left++;
        }

        while (arr[right] > arr[partitionIndex])
        {
            right--;
        }

        if (left < partitionIndex && right > partitionIndex)
        {
            swap(arr[left++], arr[right--]);
        }
    }

    return partitionIndex;
}

int largest(vector<int> &arr)
{
    if (arr.size() == 0)
        return -1;
    int maxi = arr[0];

    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }

    return maxi;
}

void Quicksort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int p = partition(arr, low, high);

    Quicksort(arr, low, p - 1);
    Quicksort(arr, p + 1, high);
}

int main()
{
    vector<int> arr = {5, 6, 2, 1, 9, 8, 6, 4};
    Quicksort(arr, 0, arr.size() - 1);
    printMe(arr);
    return 0;
}
