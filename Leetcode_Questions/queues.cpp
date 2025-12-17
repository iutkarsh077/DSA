#include <iostream>
#include <queue>
using namespace std;

class MyQueue
{
public:
    int *arr;
    int size;
    int front = -1;
    int rear = -1;

    MyQueue(int size)
    {
        this->size = size;
        arr = new int[this->size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        if (rear >= this->size - 1)
        {
            cout << "Queue is already full" << endl;
            return;
        }

        rear++;
        this->arr[rear] = data;
        if (front == -1)
        {
            front = rear;
        }
    }

    void showFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front is: " << this->arr[front] << endl;
    }

    void showBack()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Rear is: " << this->arr[this->rear] << endl;
    }

    void queueLength()
    {
        if (front == -1 && rear == -1)
        {
            cout << "queue is empty" << endl;
        }

        cout << rear - front + 1 << endl;
    }

    void isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Yes, queue is empty" << endl;
            return;
        }
        cout << "No, Queue have values" << endl;
    }

    void pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front++;
        if (front >= rear)
        {
            front = -1;
            rear = -1;
        }
    }
};

class MyCircularQueue
{
public:
    int *arr;
    int size;
    int front = -1;
    int rear = -1;

    MyCircularQueue(int size)
    {
        this->size = size;
        arr = new int[this->size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is already full" << endl;
            return;
        }
        rear++;
        rear = rear % this->size;
        this->arr[rear] = data;
        if (front == -1)
        {
            front = rear;
        }
    }

    void showFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front is: " << this->arr[front] << endl;
    }

    void showBack()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Rear is: " << this->arr[this->rear] << endl;
    }

    void queueLength()
    {
        if (front == -1)
            cout << "Queue is empty" << endl;
        else if (rear >= front)
            cout << rear - front + 1 << endl;
        else
            cout << size - (front - rear - 1) << endl;
    }

    void isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Yes, queue is empty" << endl;
            return;
        }
        cout << "No, Queue have values" << endl;
    }

    void pop()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
};

void stlQueue()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    // q.pop();
    cout << "Front is: " << q.front() << endl;
    cout << "Back is: " << q.back() << endl;

    cout << "Is queue empty? " << q.empty() << endl;

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    // stlQueue();
    MyQueue q(5);
    q.isEmpty();
    q.push(1);
    q.push(2);
    q.queueLength();
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(1092);
    q.showFront();
    q.showBack();
    q.isEmpty();
    q.queueLength();
    return 0;
}