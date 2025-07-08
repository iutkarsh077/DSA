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

class CircularQueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void EnQueue(int data)
    {
        if ((this->front == 0 && this->rear == this->size - 1) || (this->rear + 1 == this->front))
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (this->front > 0 && this->rear == this->size - 1)
        {
            this->rear = 0;
            arr[this->rear] = data;
            return;
        }

        if (this->front == -1 && this->rear == -1)
        {
            this->front = this->rear = 0;
            arr[this->rear] = data;
            return;
        }

        rear = rear + 1;
        arr[rear] = data;
    }

    void DeQueue()
    {
        if (this->front == -1)
        {
            cout << "Queue is already empty" << endl;
            return;
        }

        if (this->front == this->rear)
        {
            this->front = this->rear = -1;
            return;
        }

        if (this->front == this->size - 1)
        {
            this->front = 0;
            return;
        }

        this->front = this->front + 1;
    }

    void Front()
    {
        if (this->front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front is: " << this->arr[this->front] << endl;
    }

    void Back()
    {
        if (this->front == -1 || this->rear == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Back is: " << this->arr[this->rear] << endl;
    }

    void isEmpty()
    {
        if (front == -1)
        {
            cout << "Yes, queue is empty" << endl;
        }
        else
        {
            cout << "No, Queue is not empty" << endl;
        }
    }

    
};

int main()
{
    CircularQueue q(5);
    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    q.EnQueue(4);
    q.EnQueue(5);
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.EnQueue(4);
    q.EnQueue(5);
    q.Front();
    q.Back();
    return 0;
}