#include <bits/stdc++.h>
using namespace std;

/*class Queue
{
    int size;
    int front, rear;
    int *arr;

public:
    Queue(int n)
    {
        this->size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

     vector<int> twoSum(vector<int>& nums, int target) {
        
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }

        return { -1, -1 };
    }
    

    void Enqueue(int data)
    {
        if (rear >= size - 1)
        {
            cout << "Queue is already fulll" << endl;
        }

        else
        {
            if (front == -1)
            {
                front = 0;
            }

            arr[++rear] = data;
        }
    }

    void val()
    {
        cout << front << endl;
        cout << rear << endl;
    }

    void DeQueue()
    {
        if (rear < 0)
        {
            cout << "Queue is empty";
            front = -1;
        }
        else
        {
            rear--;
            if (rear < 0)
            {
                front = -1;
            }
        }
    }

    void top()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty part 2" << endl;
        }

        else
        {
            cout << arr[rear] << endl;
        }
    }

    void isempty()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Yes, Queue is Empty" << endl;
        }

        else
        {
            cout << "No, Queue is not Empty" << endl;
        }
    }
};*/


class Queue2{
    private:
    queue<int> q2;

    void Push(int data){
        
    }

    void pop(){
        q2.back();
    };
};

int main()
{
    return 0;
}