#include<bits/stdc++.h>
using namespace std;

/*int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

int main(){
    string s = "(p+q)*(m-n)";
    string ans = "";
    stack<char> st;

    int i = 0;
    int n = s.length();

    while(i < n){
        int c = s[i];

        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
            ans += s[i];
        }

        else if(c == '('){
            st.push(c);
        }
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while(!st.empty() && prec(c) <= prec(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
        i++;
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    cout << "The result is  " << ans << endl;
    return 0;
}*/


int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

int main(){
     string s = "(p+q)*(m-n)";
     string ans = "";
     int i = 0;
     int n = s.length();
     stack<char> st;
     while(i < n){
        char c = s[i];
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '1' && c <= '9')){
            ans += c;
        }

        else if(c == '('){
            st.push(c);
        }

        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && prec(c) <= prec(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
        i++;
     }

     while(!st.empty()){
        ans += st.top();
        st.pop();
     }

     cout << ans;
     return 0;
}