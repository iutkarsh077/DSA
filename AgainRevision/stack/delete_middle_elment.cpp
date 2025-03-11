#include <bits/stdc++.h>
using namespace std;

class MyStack{
    stack<int> st;
    public:
    MyStack(int s){
        for(int i = 0; i < s; i++) st.push(i);
    }

    void printAll(){
        int cnt = 0;
        while(!st.empty()){
            cnt++;
            cout << st.top() << " ";
            st.pop();
        }
    }

    void myMiddle(int cnt, stack<int>&st, int size){
        if(cnt == size/2){
           st.pop();
           return;
        }
     
        int num = st.top();
        st.pop();
        cnt++;
        myMiddle(cnt, st, size);
        st.push(num);
     }

    void deleteMiddleElement(){
        vector<int> arr;
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }

        int i = arr.size() - 1;
        while(i >= 0){
            if(i == arr.size()/2){
                i--;
                continue;
            }
            st.push(arr[i]);
            i--;
        }
    }
};

int main() {
    MyStack st1(5);
    st1.deleteMiddleElement();
    cout << endl;
    st1.printAll();
    return 0;
}