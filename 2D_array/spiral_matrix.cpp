#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7 ,8},
        {9, 10, 12, 13}};

    int i = 0;
    vector<int> ans;

    for (int j = 0; j < matrix[0].size(); j++)
    {
        ans.push_back(matrix[i][j]);
    }

    i = matrix[0].size() - 1;

    for (int j = 1; j < matrix.size(); j++)
    {
        ans.push_back(matrix[j][i]);
    }

    i = matrix.size() - 1;

    for (int j = matrix[0].size() - 2; j >= 0; j--)
    {
        ans.push_back(matrix[i][j]);
    }

    i = matrix.size() - 2;

    for (int j = 0; j < matrix[0].size() - 1; j++)
    {
        ans.push_back(matrix[i][j]);
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}