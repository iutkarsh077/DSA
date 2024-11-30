#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    set<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        st.insert(arr[i]);
    }

    arr.clear();

    for(auto i = st.begin(); i != st.end(); i++){
        arr.push_back(*i);
    }

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    return 0;
}