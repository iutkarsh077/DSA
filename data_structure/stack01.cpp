#include<bits/stdc++.h>
using namespace std;

void myStack(){
    stack<string> names;

    names.push("BMW");
    names.push("Volvo");
    names.push("Polo");
    names.push("Honda");

    while(!names.empty()){
        cout << names.top() << " ";
        names.pop();
    }
}

class customStack{
    public:
    int *arr;
    int size;
    int top = -1;
    customStack(int length){
        this->arr = new int[length];
        this->size = length;
    }

    void push(int data){
        if(top >= size){
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = data;
    }

    void pop(){
        if(top < 0){
            cout << "stack is empty" << endl;
            return;
        }
        top--;
    }

    void isEmpty(){
        if(top > -1){
            cout << "No, stack is not empty" << endl;
        }
        else{
            cout << "Yes, stack is empty" << endl;
        }
    }

    void StackLength(){
        cout << top + 1 << endl;
    }
};

int main(){
    customStack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.isEmpty();
    st.pop();
    st.StackLength();
    return 0;
}