#include<bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    string s = "(p+q)*(m-n)";
    string ans = "";
    stack<char> st;
    
    // Reverse the input string
    reverse(s.begin(), s.end());

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the character is an operand, add it to the output
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            ans += c;
        }

        // If the character is '(', push it to the stack
        else if (c == '(') {
            st.push('(');
        }

        // If the character is ')', pop and add to output until '(' is encountered
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is encountered
        else {
            while (!st.empty() && prec(c) <= prec(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    // Reverse the output to get the prefix expression
    reverse(ans.begin(), ans.end());

    cout << "The prefix expression is: " << ans << endl;
    return 0;
}
