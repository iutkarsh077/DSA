#include <iostream>
using namespace std;

class DoublyQueue {
public:
    int *arr, front, rear, size;

    DoublyQueue(int n) {
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
    DoublyQueue d(6);
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