#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    int i = 1;

    while (i < 6)
    {
        q.push(i);
        i++;
    }

    vector<int> arr;

    while (!q.empty())
    {
        arr.push_back(q.front());
        q.pop();
    }

    reverse(arr.begin(), arr.end());
    i = 0;
    while (i < arr.size())
    {
        q.push(arr[i]);
        i++;
    }

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}