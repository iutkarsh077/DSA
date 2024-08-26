#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "pq-ra/-";
    stack<string> st;
    int i = 0;
    int n = s.length();

    while (i < n) {
        char c = s[i];
        
        // If the character is an operand (a-z, A-Z, 0-9)
        if (isalnum(c)) {
            string h(1, c); // Convert character to string
            st.push(h);
        }
        // If the character is an operator
        else {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string val = '(' + b + c + a + ')';
            st.push(val);
        }
        i++;
    }

    cout << "The Infix is: " << st.top() << endl;
    return 0;
}
