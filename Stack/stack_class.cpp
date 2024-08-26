#include <bits/stdc++.h>
using namespace std;

class stack1
{
    int *arr;
    int top;
    int size;

public:
    stack1(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data)
    {
        if (size - top > 1)
        {
            arr[++top] = data;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }

    void Peek()
    {
        if (top >= 0)
        {
            cout << arr[top] << endl;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }

    void isEmpty()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack is not empty" << endl;
        }
    }
};

int main()
{
    stack1 s1(7);

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    s1.Peek();
    s1.pop();
    s1.Peek();

    s1.isEmpty();
    return 0;
}