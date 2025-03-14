#include <bits/stdc++.h> 
using namespace std;

void reverseStack(stack<int> &newStack) {
    stack<int> st;
 
    while(!newStack.empty()){
        st.push(newStack.top());
        newStack.pop();
    }
 
    newStack = st;
 }
 

void myBottom(stack<int>&st, int x){
        if(st.empty()){
           st.push(x);
           return;
        }
     
        int num = st.top();
        st.pop();
        myBottom(st, x);
        st.push(num);
   }

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
  
    int size = myStack.size();
    myBottom(myStack, x);
    return myStack;
}