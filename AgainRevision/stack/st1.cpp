#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<float> st;
    st.push(1.44);
    st.push(3.53);
    // st.push("Praveen");
    // st.push("Sameer");

    cout << "Size is: " << st.size() << endl;

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}