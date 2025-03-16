#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

void SortStack(stack<int> &st){
    vector<int> arr;
    while(!st.empty()){
        arr.push_back(st.top());
        st.pop();
    }

    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        st.push(arr[i]);
    }
}


int main() {
    stack<int> st;

  st.push(6);
  st.push(2);
  st.push(8);
  st.push(9);
  st.push(3);
  st.push(78);
  st.push(100);

    SortStack(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}