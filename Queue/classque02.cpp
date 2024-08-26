#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int front, rear, size;
    int *array;

public:
    Queue(int size)
    {
        front = rear = 0;
        this->size = size;
        array = new int[size];
    }

    void enQueue(int value)
    {
        if (front == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            array[front++] = value;
        }
    }

    void DeQueue()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            front--;
        }
    }

    void RearView()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            cout << array[rear];
        }
    }

    void Display()
    {
        if (front == rear)
        {
            cout << "Nothing To print Here Queue is empty";
            return;
        }
        for (int i = rear; i < front; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void Size()
    {
        if (front == rear)
        {
            cout << endl
                 << "Size is 0" << endl;
        }
        else
        {
            cout << "Size of the queue is: " << front - rear << endl;
        }
    }
};

int main()
{
    Queue q(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.Display();
    q.Size();
    q.RearView();
    return 0;
}