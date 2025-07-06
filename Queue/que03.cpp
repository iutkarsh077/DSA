#include <iostream>
#include <queue>
using namespace std;

class MyQueue
{
public:
    int front;
    int rear;
    int *arr;
    int size;

    MyQueue(int size)
    {
        this->front = 0;
        this->rear = 0;
        this->arr = new int[size];
        this->size = size;
    }

    void enQueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is Full" << endl;
            return;
        }

        arr[rear] = data;
        rear++;
    }

    int deQueue()
    {
        if (front == rear)
        {
            front = 0;
            rear = 0;
            cout << "Queue is empty" << endl;
            return -1;
        }

        int popElement = arr[front];
        front = front + 1;
        return popElement;
    }

    void isEmpty()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            cout << "Queue have elements";
        }
    }

    void Front()
    {
        if (front == rear)
        {
            cout << "Queue is empty, no front" << endl;
            return;
        }
        else
        {
            cout << "Front is: " << arr[front] << endl;
        }
    }

    void myback()
    {
        if (front == rear)
        {
            cout << "Queue is empty, no back" << endl;
            return;
        }
        else
        {
            cout << "Back is: " << arr[rear - 1] << endl;
        }
    }
};

void extra1()
{
    queue<int> q;

    q.push(7);
    q.push(67);
    q.push(2);

    q.pop();
    cout << "The front is: " << q.front() << endl;
    cout << "The back is: " << q.back() << endl;
    cout << "The size is: " << q.size() << endl;
}

int main()
{
    MyQueue q(5);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.Front();
    q.myback();

    return 0;
}