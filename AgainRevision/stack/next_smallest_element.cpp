#include <bits/stdc++.h>
using namespace std;

vector<int> nextsmallestElement(vector<int> arr, int n){
    stack<int> st;
    st.push(-1);
    vector<int> myarr(n);
    for(int i = n - 1; i >= 0; i--){
        int curr = arr[i];

        while(st.top() >= curr) st.pop();

        myarr[i] = st.top();
        st.push(curr);
    }

    return myarr;
}

int main() {
    vector<int> arr = {2, 1, 4, 3};
    vector<int> myarr = nextsmallestElement(arr, arr.size());

    for(int i = 0; i < myarr.size(); i++){
        cout << myarr[i] << " ";
    }
    return 0;
}