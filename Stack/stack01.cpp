#include <bits/stdc++.h>
using namespace std;

class Stack1
{
public:
    int *arr;
    int top = -1;
    int size = -1;
    Stack1(int size)
    {
        arr = new int[size];
        top = -1;
        this->size = size;
    }

    ~Stack1()
    {
        delete[] arr;
    }

    void push(int data)
    {
        if (top >= this->size - 1)
        {
            cout << "Stack is already full" << endl;
            return;
        }
        top = top + 1;
        arr[top] = data;
    }

    void pop()
    {
        if (top == -1)
            return;
        top--;
    }

    void isEmpty()
    {
        if (top == -1)
        {
            cout << "Yes, Stack is Empty";
            return;
        }
        if (top >= this->size - 1)
        {
            cout << "Stack is full";
        }
        else
        {
            cout << "Stack have space";
        }
        cout << endl;
    }

    void Peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        cout << arr[top] << endl;
    }
};

int main()
{
    Stack1 st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    st.push(6);
    st.Peek();
    st.isEmpty();
    return 0;
}