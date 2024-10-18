#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result;

    // TopElement
    for (int i = 0; i < arr[0].size(); i++)
    {
        result.push_back(arr[0][i]);
    }

    // RightElement
    int colLength = arr[0].size();
    for (int i = 1; i < arr.size(); i++)  
    {
        result.push_back(arr[i][colLength - 1]);
    }

    // BottomElement
    for (int i = colLength - 2; i >= 0; i--) 
    {
        result.push_back(arr[arr.size() - 1][i]);
    }

    // LeftElement (adding to form a spiral traversal)
    for (int i = arr.size() - 2; i > 0; i--) 
    {
        result.push_back(arr[i][0]);
    }

    for (int i = 1; i < colLength - 1; i++) 
    {
        result.push_back(arr[arr.size() - 2][i]);
    }

    // Print the result
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
