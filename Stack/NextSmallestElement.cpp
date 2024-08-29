#include<bits/stdc++.h>
using namespace std;

//Approach 1
/*int main(){
     vector<int> A = {1};
      vector<int> result;

    for(int i = 0; i < A.size(); i++){
        bool flag = true;
        int j = i - 1;
        while(j >= 0){
            if(A[j] < A[i]){
                result.push_back(A[j]);
                flag = false;
                break;
            }
            j--;
        }
        if(flag == true){
            result.push_back(-1);
        }
    }
    int i = 0;
    while(i < result.size()){
        cout << result[i] << " ";
        i++;
    }
    return 0;
}*/



/*int main(){
    vector<int> A = {2, 1, 6, 5, -2, 7, 1};

    stack<int> st;
    vector<int> result(A.size(), -1);

    for(int i = 0; i < A.size(); i++){
        while(!st.empty() && st.top() >= A[i]){
            st.pop();
        }

        if(i < A.size()){
            result[i] = st.empty() ? -1 : st.top();
        }

        st.push(A[i]);
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}*/


int main(){
    vector<int> A = {2, 1, 6, 5, -2, 7, 1};
    stack<int> st;
    vector<int> result(A.size(), -1);
    int i = 0;

    while(i < A.size()){
        while(!st.empty() && st.top() >= A[i]){
            st.pop();
        }

        if(i < A.size()){
            result[i] = st.empty() ? -1 : st.top();
        }

        st.push(A[i]);
        i++;
    }

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}