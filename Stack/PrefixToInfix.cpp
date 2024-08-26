#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "--pq/ra";
    stack<string> st;
    int i = s.length() - 1;
    int n = s.length();

    while (i >= 0) {
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
        i--;
    }
    
    string ans = st.top();
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.length(); i++){
        if(ans[i] == '('){
            ans[i] = ')';
        }
        else if(ans[i] == ')'){
            ans[i] = '(';
        }
    }

    cout << "The Infix is: " << ans << endl;
    return 0;
}
