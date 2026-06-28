#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this->arr = new int[size];
        this->size = size;
        top = -1;

    }

    void push(int data){
        if(this->top >= this->size - 1){
            cout << "Stack Overflow" << endl;
            return;
        }
        this->top++;
        arr[this->top] = data;
    }

    int pop(){
        if(this->top < 0){
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int val = this->arr[top];
        this->top--;
        return val;
    }

    void peek(){
        if(this->top < 0){
            cout << "Stack is empty" << endl;
            return;
        }

        cout <<"Peek is: " << this->arr[top] << endl;
    }

    void getSize(){
        cout << "Size of stack is: " << this->size << endl;
    }
};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout << st.pop() << endl;
    st.peek();
    return 0;
}