#include<bits/stdc++.h>
using namespace std;

class Queue1{
    public:
    int *arr;
    int size;
    int front;
    int back;
    Queue1(int size){
        this->arr = new int[size];
        this->size = size;
        this->front = -1;
        this->back = -1;
    }

    void push(int data){
        if(this->back >= this->size - 1){
            cout << "Queue Overflow" << endl;
            return;
        }

        this->arr[back] = data;
        if(this->front == -1){
            this->front = 0;
        }
        this->back++;
    }

    void pop(){
        if(this->front < 0){
            cout << "Stack Underflow" << endl;
            this->front = -1;
            this->back = -1;
            return;
        }

        cout << "Removed variable is: " << this->arr[this->front] << endl;
        this->front--;
        if(this->front <= this->back){
            this->front--;
            this->back--;
        }
    }
};

int main(){
    Queue1 q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.push(6);
    return 0;
}