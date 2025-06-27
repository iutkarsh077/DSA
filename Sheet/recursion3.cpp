#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

void IterativeKthSymbol()
{
    vector<vector<int>> result;
    int n = 3;
    int k = 4;
    result.push_back({0});
    for (int i = 1; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < result[i - 1].size(); j++)
        {
            int upperVal = result[i - 1][j];
            if (upperVal == 0)
            {
                temp.push_back(0);
                temp.push_back(1);
            }
            if (upperVal == 1)
            {
                temp.push_back(1);
                temp.push_back(0);
            }
        }
        result.push_back(temp);
    }

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            if (n - 1 == i && k - 1 == j)
            {
                cout << "The value is: " << result[i][j];
                return;
            }
        }
    }
}

int solve(int n, int k){
    if(n == 1 || k == 1){
        return 0;
    }

    int len = pow(2, n - 1);
    int mid = len/2;

    if(k <= mid){
        return solve(n - 1, k);
    }
    else{
        return !solve(n - 1, k - mid);
    }
}

void reverseStr(string str, int index){
    if(index >= str.length()) return;

    reverseStr(str, index + 1);
    cout << str[index] << " ";
}

int main()
{
    // int ans = solve(4, 5);
    // cout << ans;

    reverseStr("Project", 0);
    
    return 0;
}