#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

/*
bool isValidParenthesis(string s)
{
    stack<char> st;

    for(int i = 0; i < s.length(); i++){
        char alpha = s[i];

        if(alpha == '{' || alpha == '(' || alpha == '['){
            st.push(alpha);
        }

        else if(alpha == '}' || alpha == ')' || alpha == ']'){

            if(st.empty()) return false;
            char myTop = st.top();
            st.pop();

            if((alpha == '}' && myTop != '{') || (alpha == ')' && myTop != '(') || (alpha == ']' && myTop != '[')){
                return false;
            }
        }
    }

    return true;
}
    */


bool validParenthesis(string str, int size){
    stack<char> st;
    
    for(int i = 0; i < str.length(); i++){
        char ch = str[i];

        if(ch == '{' || ch == '(' || ch == '[') st.push(ch);

        else if(ch == '}' || ch == ')' || ch == ']'){
            if(st.empty()) return false;

            char mytop = st.top();
            st.pop();
            if((ch == '}' && mytop != '{') || (ch == ')' && mytop != '(') || ((ch == ']' && mytop != '['))){
                return false;
            }
        }
    }

    return true;
}

int main() {
    return 0;
}