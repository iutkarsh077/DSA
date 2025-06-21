#include <iostream>
#include <climits>
#include <vector>
#include<stack>
using namespace std;

void printN(int n)
{
    if (n == 0)
    {
        return;
    }

    printN(n - 1);
    cout << n << " ";
}

int facto(int n)
{
    if (n == 1)
        return 1;

    return n * facto(n - 1);
}

int selectme(int i, vector<int> arr, int maxi)
{
    if (i == arr.size())
        return maxi;

    if (arr[i] < arr[maxi])
    {
        maxi = i;
    }

    return selectme(i + 1, arr, maxi);
}

void printArr(vector<int> arr, int i)
{
    if (i == arr.size())
        return;

    cout << arr[i] << ' ';

    printArr(arr, i + 1);
}

void recur(vector<int> &arr, int maxi, int i)
{
    if (i == arr.size())
        return;

    maxi = i;
    maxi = selectme(i + 1, arr, maxi);
     swap(arr[maxi], arr[i]);

     recur(arr, maxi, i + 1);
}


void rev(int top, stack<int> &st, int start, int end){
    if(start >= end - 1 || st.empty()){
        st.push(top);
        return;
    }

    int mytop = st.top();
    st.pop();

    rev(top, st, start + 1, end);
    st.push(mytop);
}

int main()
{
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(1);
    st.push(3);
    st.push(8);

    int cnt = 0;
    int len = st.size();
    while(cnt < len){
        int top = st.top();
        st.pop();
        rev(top, st, 0, len - cnt);
        cnt = cnt + 1;
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}