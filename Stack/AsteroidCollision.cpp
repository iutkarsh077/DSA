#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<int> arr = {-2, -1, 1, 2};

    stack<int> st;
    int i = 0;

    while (i < arr.size())
    {
        if (st.empty() || (arr[i] > 0 && st.top() > 0) || (st.top() < 0 && arr[i] < 0))
        {
            st.push(arr[i]);
            i++;
        }

        else if ((st.top() < 0 && arr[i] > 0) || (st.top() > 0 && arr[i] < 0))
        {
            if (abs(st.top()) > abs(arr[i]))
            {
                i++;
            }

            else if (abs(st.top()) < abs(arr[i]))
            {
                st.pop();
            }

            else if (abs(st.top()) == abs(arr[i]))
            {
                i++;
                st.pop();
            }
        }

        else{
            i++;
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    arr.clear();
    cout << endl << arr.size();
    return 0;
}