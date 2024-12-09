#include <bits/stdc++.h>
using namespace std;

class ArrayProblem
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        result.push_back({1});

        if(numRows == 1){
            return result;
        }

        for (int i = 1; i < numRows; i++)
        {
            vector<int> val;
            for (int j = 0; j < i + 1; j++)
            {
                if(j == 0 || j == i){
                    val.push_back(1);
                }
                else 
                {
                    int digit = result[i - 1][j - 1] + result[i - 1][j];
                    val.push_back(digit);
                }
            }
            result.push_back(val);
        }
        return result;
    }
};

int main()
{
    ArrayProblem arr;
    vector<vector<int>> result = arr.generate(5);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}