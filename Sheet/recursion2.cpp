#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void printN(int n)
{
    if (n == 0)
    {
        return;
    }

    printN(n - 1);
    cout << n << " ";
}

int facto(int n)
{
    if (n == 1)
        return 1;

    return n * facto(n - 1);
}

int selectme(int i, vector<int> arr, int maxi)
{
    if (i == arr.size())
        return maxi;

    if (arr[i] < arr[maxi])
    {
        maxi = i;
    }

    return selectme(i + 1, arr, maxi);
}

void printArr(vector<int> arr, int i)
{
    if (i == arr.size())
        return;

    cout << arr[i] << ' ';

    printArr(arr, i + 1);
}

void recur(vector<int> &arr, int maxi, int i)
{
    if (i == arr.size())
        return;

    maxi = i;
    maxi = selectme(i + 1, arr, maxi);
     swap(arr[maxi], arr[i]);

     recur(arr, maxi, i + 1);
}

int main()
{
    int maxi = INT_MIN;
    vector<int> arr = {9, 2, 31, 8, 72, 6, 40, 31};
    recur(arr, INT_MIN, 0);
    printArr(arr, 0);
    return 0;
}