#include<iostream>
#include<stack>
using namespace std;



void InsertAtBottom(int x, stack<int>&st){
    if(st.empty()){
        st.push(x);
        return;
    }

    int num = st.top();
    st.pop();

    InsertAtBottom(x, st);
    st.push(num);
}

void reverseStack(stack<int> &stack) {
    if (stack.empty()) {
        return;
    }

    int topElement = stack.top();
    stack.pop();

    reverseStack(stack); 
    InsertAtBottom(topElement, stack); 
}


int main(){
    string name = "Utkarsh";
    stack<char> st;
    int i = 0;
    while(i < name.size()){
       st.push(name[i]);
       i++;
    }

    name.erase();
    while(!st.empty()){
        cout << st.top();
        st.pop();
     }
   
    return 0;
}