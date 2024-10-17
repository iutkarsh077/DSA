#include <bits/stdc++.h>
using namespace std;

void makeRowZero(vector<vector<int>> &arr, int j)
{
    for (int k = 0; k < arr.size(); k++)
    {
        arr[k][j] = INT_MIN;
    }
}

void makeColZero(vector<vector<int>> &arr, int i)
{
    for (int k = 0; k < arr[i].size(); k++)
    {
        arr[i][k] = INT_MIN;
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == 0)
            {
                makeRowZero(arr, j);
                makeColZero(arr, i);
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == INT_MIN)
            {
                arr[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}