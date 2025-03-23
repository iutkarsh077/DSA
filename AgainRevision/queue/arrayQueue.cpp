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
        if (rear >= size - 1) {  // Corrected overflow condition
            cout << "Queue Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = val;
    }

    void PopIntoQueue() {
        if (front > rear) {  // Corrected underflow condition
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
        if (rear == -1) {  // Corrected condition
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

        for (int i = front; i <= rear; i++) { // Fixed loop condition
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n = 6;
    CustomQueue q1(n);
    
    for (int i = 1; i <= n; i++) {
        q1.PushIntoQueue(i);
    }

    q1.printAllQueue();  // Expected Output: 1 2 3 4 5 6

    return 0;
}
