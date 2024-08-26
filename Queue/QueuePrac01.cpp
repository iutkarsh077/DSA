#include <iostream>
using namespace std;

class MyQueue {
public:
    int *arr;
    int len;
    int front;
    int back;

    MyQueue(int size) {
        this->len = size;
        arr = new int[len];
        front = -1;
        back = -1;
    }

    ~MyQueue() {
        delete[] arr;
    }

    void PushData(int data) {
        if (back >= len - 1) {
            cout << "Queue is already full" << endl;
            return;
        }
        back++;
        arr[back] = data;
        if (front == -1) { // first element
            front = 0;
        }
    }

    void PopData() {
        if (front == -1) {
            cout << "Queue is already empty" << endl;
            return;
        }

        if (front > back) {
            front = -1;
            back = -1;
            cout << "Queue is now empty" << endl;
            return;
        }

        front++;
    }

    void myFront() {
        if (front == -1 || front >= len - 1) {
            cout << "No front, Queue is empty" << endl;
            return;
        }

       
        cout << "Front element: " << arr[front] << endl;
    }

    void myBack() {
        if (back == -1) {
            cout << "No back element, Queue is empty" << endl;
            return;
        }
        cout << "Back element: " << arr[back] << endl;
    }
};

int main() {
    MyQueue q1(5);
    q1.myFront();
    q1.myBack();
    q1.PushData(1);
    q1.PushData(2);
    q1.PushData(3);
    q1.PushData(40);
    q1.PopData();
    q1.PopData();
    q1.PopData();
    q1.PopData();
    q1.myFront();
    q1.myBack();
    return 0;
}
