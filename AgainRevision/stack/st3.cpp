#include <iostream>
using namespace std;

class TwoStack {
public:
    int top1, top2;
    int *arr;
    int size;

    TwoStack(int s) {
        size = s;
        arr = new int[s];
        top1 = -1;
        top2 = s; 
    }

    void push1(int data) {
        if (top1 + 1 == top2) {
            cout << "Stack1 Overflow" << endl;
            return;
        }
        arr[++top1] = data;
    }

    void push2(int data) {
        if (top2 - 1 == top1) {
            cout << "Stack2 Overflow" << endl;
            return;
        }
        arr[--top2] = data;
    }

    void pop1() {
        if (top1 < 0) {
            cout << "Stack1 Underflow" << endl;
            return;
        }
        top1--;
    }

    void pop2() {
        if (top2 >= size) {
            cout << "Stack2 Underflow" << endl;
            return;
        }
        top2++;
    }

  
};

int main() {
    TwoStack st(5);
    st.push1(2);
    st.push2(3);
    st.push2(4);
    st.push2(67);
    st.push1(1889);

    return 0;
}
