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

    int mytop = -1;
    if(top < st.top()){
        mytop = top;
        top = st.top();
        st.pop();
    }
    else{
         top = max(st.top(), top);
        mytop = st.top();
        st.pop();
    }

    rev(top, st, start + 1, end);
    st.push(mytop);
}

void myStack(){
     stack<int> st;
    st.push(5);
    st.push(2);
    st.push(1);
    st.push(8);
    // st.push(5);

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
}

void deleteMiddle(stack<int> &st, int count, int len){
    if(count == len/2){
        st.pop();
        return;
    }

    int element = st.top();
    st.pop();

    deleteMiddle(st, count + 1, len);
    st.push(element);
}

void printStack(stack<int> st){
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

void deleteMe(stack<int> st){
     deleteMiddle(st, 0, st.size());
    printStack(st);
}

void reverseStack(stack<int> &st, int end, int start, int val){
    if(st.empty() || end - 1 == start){
        st.push(val);
        return;
    }

    int mytop = st.top();
    st.pop();

    reverseStack(st, end, start + 1, val);
    st.push(mytop);
};

int facto(int n, int &multiple){
    if(n == 0) return 1;

    multiple = multiple * n;
    return facto(n - 1, multiple);
}

int main()
{
   stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    int cnt = 0;
    int len = st.size();

    // for(int i = 0; i < len; i++){
    //     int top = st.top();
    //     st.pop();
    //     reverseStack(st, len - cnt, 0, top);
    //     cnt++;
    // }

    // printStack(st);

    int multiple = 1;
    int ans = facto(5, multiple);
    cout << "The answer is: " << multiple;
    return 0;
}