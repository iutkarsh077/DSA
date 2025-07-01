#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
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

int solve(int n, int k)
{
    if (n == 1 || k == 1)
    {
        return 0;
    }

    int len = pow(2, n - 1);
    int mid = len / 2;

    if (k <= mid)
    {
        return solve(n - 1, k);
    }
    else
    {
        return !solve(n - 1, k - mid);
    }
}

void reverseStr(string str, int index)
{
    if (index >= str.length())
        return;

    reverseStr(str, index + 1);
    cout << str[index] << " ";
}

void reverseNumber(int n)
{
    if (n <= 0)
        return;

    int digit = n % 10;
    cout << digit << " ";
    n = n / 10;
    reverseNumber(n);
}

void reverseStack(stack<int> &st, int start, int end, int val)
{
    if (st.empty() || start == end - 1)
    {
        st.push(val);
        return;
    }

    int mytop = st.top();
    st.pop();

    reverseStack(st, start + 1, end, val);
    st.push(mytop);
}

void toh(int n, char from_rod, char to_rod,
         char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    toh(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    toh(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(7);
    st.push(6);

    int len = st.size();
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        int top = st.top();
        st.pop();

        reverseStack(st, 0, len - count, top);
        count++;
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}