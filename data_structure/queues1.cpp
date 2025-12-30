#include<bits/stdc++.h>
using namespace std;

void stlQueue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    q.pop();
    cout << "Front is: " << q.front() << endl;
    cout << "Rear is: " << q.back() << endl;
    cout << "Is empty: " << q.empty() << endl;
    cout << "Size is: " << q.size() << endl;
}


class CustomQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    CustomQueue(int len){
        this->size = len;
        arr = new int[len];
        front = -1;
        rear = -1;
    }


    void enQueue(int data){
        if(rear == size){
            cout << "Queue is full" << endl;
            return;
        }

        rear++;
        arr[rear] = data;
        if(front == -1) front++;
    }

    void deQueue(){
        if(front == rear){
            front = rear = -1;
            return;
        }
        front++;
    }

    void isEmpty(){
        if(rear >= 0){
            cout << "Queue has values" << endl;
            return;
        }
        cout << "Queue is empty" << endl;
    }

    void LookFront(){
        if(front < 0){
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front element is: " << arr[front] << endl;
    }

    void LookBack(){
        if(rear < 0){
            cout << "Queue is empty" << endl;
            return;
        }

         cout << "Rear element is: " << arr[rear] << endl;
    }
};

int main(){
    CustomQueue q(5);
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.LookFront();
    q.LookBack();
    q.isEmpty();
    cout << "Front is: " << q.front << endl;
    cout << "Back is: " << q.rear << endl;
    cout << "Size is: " << q.size << endl;
    return 0;
}