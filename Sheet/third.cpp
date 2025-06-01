#include<iostream>
using namespace std;

 bool rotateString(string s, string goal) {
        for (int i = 0; i < s.size(); i++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal)
                return true;
        }
        return false;
    }

int main(){
    string a = "abcde";
    string b = "abcdde";
  if(a == b){
    cout << "a is equal to b";
  }
    return 0;
}