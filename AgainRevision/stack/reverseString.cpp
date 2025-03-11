#include<iostream>
#include<stack>
using namespace std;

int main(){
    string name = "Utkarsh";
    stack<char> st;
    int i = 0;
    while(i < name.size()){
       st.push(name[i]);
       i++;
    }

    name.erase();
    while(!st.empty()){
        cout << st.top();
        st.pop();
     }
   
    return 0;
}