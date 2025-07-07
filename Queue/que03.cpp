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

class CircularQueue{
    public:
    int *arr;
    int front = 0;
    int rear = -1;
    int size;

    void push(int data){
        if(rear + 1 == front || (rear == size - 1 && front == 0)){
            cout << "Queue is full" << endl;
            return;
        }

        rear++;
        rear = rear % size;
        arr[rear] = data;
    }
};

int main()
{
    return 0;
}