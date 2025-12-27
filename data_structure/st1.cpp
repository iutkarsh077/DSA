#include<iostream>
using namespace std;

class MyStack{
    public:
    int *arr;
    int size;
    int top;

    MyStack(int size1){
        this->arr = new int[size1];
        this->size = size1;
        this->top = -1;
    }

    void push(int data){
        if(top >= size){
            cout << "Stack is already full" << endl;
            return;
        }

        top++;
        arr[top] = data;
    }


    void pop(){
        if(top < 0){
            cout << "Stack Underflow" << endl;
            return;
        }

        top--;
    }


    void peak(){
        if(top < 0){
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << arr[top] << endl;
    }


    void Length(){
        if(top < 0){
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << "Size of Stack is: " << this->top + 1 << endl;
    }
};

int main(){
    MyStack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.Length();
    st.peak();
    return 0;
}