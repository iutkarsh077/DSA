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

void extra2(){
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
}

class Deque {
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    Deque(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = 0;
    }

    // Check if deque is full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (front == rear + 1);
    }

    // Check if deque is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insert at front
    void insertFront(int key) {
        if (isFull()) {
            cout << "Overflow: Cannot insert at front\n";
            return;
        }
        // First element
        if (front == -1) {
            front = rear = 0;
        }
        else if (front == 0) {
            front = size - 1;
        }
        else {
            front--;
        }
        arr[front] = key;
    }

    // Insert at rear
    void insertRear(int key) {
        if (isFull()) {
            cout << "Overflow: Cannot insert at rear\n";
            return;
        }
        // First element
        if (front == -1) {
            front = rear = 0;
        }
        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = key;
    }

    // Delete from front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Underflow: Cannot delete from front\n";
            return;
        }
        // Only one element
        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
    }

    // Delete from rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Underflow: Cannot delete from rear\n";
            return;
        }
        // Only one element
        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return -1;
        }
        return arr[rear];
    }
};

int main()
{
    
    return 0;
}