#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string str){
    stack<char> st;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '{') {
            st.push(str[i]);
        }
        else if(str[i] == '}') {
            if(!st.empty() && st.top() == '{') {
                st.pop();
            }
            else {
                st.push(str[i]);
            }
        }
    }

    
    if(st.size()%2 == 0){
        int ans = st.size() / 2;
        return ans;
    }

    int ans = st.size() / 2;
    return ans - 1;
}

int main(){
    string str = "{{{}}";
    int result = findMinimumCost(str);
    cout << "The result is: " << result;
    return 0;
}