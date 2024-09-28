#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[26] = {0};
    string s = "abcdabefcz";

    for (int i = 0; i < s.length(); i++)
    {
        int val = s[i] - 97;
        arr[val] += 1; 
    }

    for(int i = 0;  i< sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i] << " ";
    }
    return 0;
}