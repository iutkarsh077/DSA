#include <iostream>
using namespace std;

class CustomQueue {
public:
    int *arr;
    int size;
    int front;
    int rear;

    CustomQueue(int n) {
        this->arr = new int[n];
        this->size = n;
        this->front = 0;
        this->rear = -1;
    }

    void PushIntoQueue(int val) {
        if (rear >= size - 1) {  
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = val;
    }

    void PopIntoQueue() {
        if (front > rear) {  
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
    }

    void CheckFront() {
        if (front > rear) {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << arr[front] << endl;
    }

    void CheckBack() {
        if (rear == -1) {  
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << arr[rear] << endl;
    }

    void printAllQueue() {
        if (front > rear) {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = front; i <= rear; i++) { 
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


class CircularQueue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    CircularQueue(int n){
        this->size = n;
        this->arr = new int[size];
        front = -1;
        rear = -1;
    }

    int pushElement(int val){
        if(((rear + 1) % size) == front){
            cout << "Queue Overflow" << endl;
            return -1;
        }

        if(front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = val;
    }

    int popElement(){
        if(front == -1){
            cout << "Queue underflow" << endl;
            return -1;
        }

        int ans = arr[front];
        if(front == rear) front = rear = -1;
        front = (front + 1) % size;
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

int main() {
    // int n = 6;
    // CustomQueue q1(n);
    
    // for (int i = 1; i <= n; i++) {
    //     q1.PushIntoQueue(i);
    // }

    // q1.printAllQueue();  

    CircularQueue q(6);
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
