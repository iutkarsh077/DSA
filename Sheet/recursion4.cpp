#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

void reachSchool(int src, int dest)
{
    if (src == dest)
    {
        cout << "Reached School" << endl;
        return;
    }

    cout << "Covered distance: " << src << endl;

    reachSchool(src + 1, dest);
}

void fibo(int n, int first, int second)
{
    if (n == 2)
        return;

    int sum = first + second;
    cout << sum << " ";
    first = second;
    second = sum;

    return fibo(n - 1, first, second);
}

void fiboIterative(int n)
{
    int first = 0;
    int second = 1;

    for (int i = 3; i <= n; i++)
    {
        int sum = first + second;
        cout << sum << " ";

        first = second;
        second = sum;
    }
}

void isSorted(int arr[], int start, int end)
{
    if (start == end - 1)
    {
        cout << "Sorted hai";
        return;
    }

    if (arr[start] > arr[start + 1])
    {
        cout << "Not sorted";
        return;
    }

    isSorted(arr, start + 1, end);
}

int main()
{
    int arr[] = {1, 2, 3, 44, 5, 6};
    isSorted(arr, 0, sizeof(arr) / sizeof(arr[0]));
    return 0;
}