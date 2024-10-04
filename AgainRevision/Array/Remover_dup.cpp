#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int i = 0;
    while (i < arr.size() - 1)
    {
        if (arr[i] == arr[i + 1])
        {
            arr.erase(arr.begin() + i + 1);
        }
        else
        {
            i++;
        }
    }
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}

/*
 set<int> s1;
    for (int i = 0; i < n; i++)
    {
        s1.insert(arr[i]);
    }


    for(auto i = s1.begin(); i != s1.end(); i++){
        cout << *i << " ";
    }*/