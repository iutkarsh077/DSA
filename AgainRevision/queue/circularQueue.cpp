/*
#include <iostream>
using namespace std;

class circularQueue {
public:
    int *arr, front, rear, size;

    circularQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void PushElement(int data) {
        if ((rear + 1) % size == front) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = data;
    }

    int popElement() {
        if (front == -1) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
        return val;
    }
};

int main() {
    circularQueue d(6);
    d.PushElement(1);
    d.PushElement(76);
    d.PushElement(45);
    d.PushElement(12);
    d.PushElement(3);
    d.PushElement(56);

    for (int i = 0; i < 7; i++) cout << d.popElement() << endl;
    d.PushElement(732);
    return 0;
}
*/


#include<iostream>
using namespace std;

class circularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    circularQueue(int n){
        this->size = n;
        arr = new int[size];
        front = rear = -1;
    }


    void pushElement(int d){
        if((rear + 1) % size == front){
            cout << "Queue Overflow";
            return;
        }

        if(front == -1) front = 0;
        rear++;
        arr[rear] = d;
    }

    int popElement(){
        if(front == -1){
            cout << "Queue is empty";
            return -1;
        }

        int ans = arr[front];
        if(front == rear){
            front = rear = -1;
        }
        else front = (front + 1) % size;
        return ans;
    }

    void printAll(){
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;  
            i = (i + 1) % size;
        }
    }
};

int main(){
    circularQueue q(6);
    q.pushElement(2);
    q.pushElement(8);
    q.pushElement(45);
    q.pushElement(98);
    q.pushElement(23);
    q.pushElement(56);

    cout << q.popElement() << endl;
    cout << q.popElement() << endl;
    cout << endl;
    cout << endl;
    q.printAll();
    return 0;
}