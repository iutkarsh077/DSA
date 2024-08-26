#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    int *arr;
    int top;
    int size;

public:
    MyStack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data)
    {
        if (top >= size - 1)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            arr[++top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "The array is underflow";
        }
        else
        {
            top--;
        }
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            cout << arr[top] << endl;
        }
    }

    void isEmpty()
    {
        if (top == -1)
        {
            cout << "Array is Empty" << endl;
        }
        else
        {
            cout << "NO array have the elements" << endl;
        }
    }
};

int main()
{
    MyStack s1(3);
    s1.push(3);
    s1.peek();
    s1.push(2);
    s1.push(78);
    s1.pop();
    s1.pop();

    s1.pop();

    s1.peek();
    s1.isEmpty();

    return 0;
}