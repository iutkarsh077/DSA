#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int nextElement(vector<int> &nums2, int value){
        bool found = false;
        for(int i = 0; i < nums2.size(); i++){
            if(nums2[i] == value){
                found = true;
                continue;
            }
            if(found == true && nums2[i] > value){
                return nums2[i];
            } 
        }

        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            vector<int> result;

            for(int i = 0; i < nums1.size(); i++){
                int ans = nextElement(nums2, nums1[i]);
                result.push_back(ans);
            }

            return result;
    }

class MyStack{
    public:
    int *arr;
    int size;
    int top;

    MyStack(int size1){
        this->arr = new int[size1];
        this->size = size1;
        this->top = -1;
    }

    void push(int data){
        if(top >= size){
            cout << "Stack is already full" << endl;
            return;
        }

        top++;
        arr[top] = data;
    }


    void pop(){
        if(top < 0){
            cout << "Stack Underflow" << endl;
            return;
        }

        top--;
    }


    void peak(){
        if(top < 0){
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << arr[top] << endl;
    }


    void Length(){
        if(top < 0){
            cout << "Stack Underflow" << endl;
            return;
        }

        cout << "Size of Stack is: " << this->top + 1 << endl;
    }
};

int main(){
    MyStack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.Length();
    st.peak();
    return 0;
}