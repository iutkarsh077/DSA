#include<bits/stdc++.h>
using namespace std;

class MyStack{
    public:
    int *arr;
    int size;
    int top = -1;

    MyStack(int size){
        this->arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int val){
        if(top >= this->size - 1){
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = val;
    }

    void pop(){
        if(top <= -1){
            cout << "Stack underflow" << endl;
            return;
        }

        int val = arr[top];
        top--;
        cout << val << " is removed" << endl;
        return;
    }

    void peak(){
        if(top <= -1){
            cout << "stack is empty" << endl;
            return;
        }

        cout << "Peak value is: " << arr[top] << endl;
    }

    void isEmpty(){
        if(top <= -1){
            cout << "Stack is empty "<< endl;
            return;
        }

        else{
            cout << "Stack has values" << endl;
        }
    }

    int mysize(){
        return this->top + 1;
    }
};

void reverseString(){
    string str = "Babbar";
    stack<char> st;

    int n = str.size();
    for(int i = 0; i < n; i++){
        st.push(str[i]);
    }

    string ans = "";
    for(int i = 0; i < n; i++){
        char character = st.top();
        ans = ans + character;
        st.pop();
    }

    cout << ans;
}

void recurDeleteMiddle(stack<int> &st, int middle, int tracker){
    if(middle == tracker){
        st.pop();
        return;
    }

    int val = st.top();
    st.pop();
    recurDeleteMiddle(st, middle, tracker + 1);
    st.push(val);
}

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans;
    stack<int> st;
    st.push(-1);
    for(int i = n - 1; i >= 0; i--){
        while(st.top() >= arr[i]){
            st.pop();
        }

        ans.push_back(st.top());
        st.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void deleteMiddle(){
    stack<int> st;
    st.push(83);
    st.push(74);
    st.push(67);
    st.push(49);
    st.push(94);
    st.push(8);
    st.push(11);
    st.push(1);

    if(st.size() == 1){
        st.pop();
        return;
    }

    int tracker = 0;
    int middle = st.size()/2;
    recurDeleteMiddle(st, middle, tracker);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}

int main(){
    // MyStack first(6);
    // first.push(1);
    // first.push(2);
    // first.push(3);
    // first.push(4);
    // first.push(5);
    // first.push(6);
    // first.push(7);
    // first.push(8);
    // first.peak();
    // first.pop();
    // first.isEmpty();
    // cout << first.mysize();
    // reverseString();
    deleteMiddle();
    return 0;
}