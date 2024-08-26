#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[25] = {0};
    string str = "testsample";
    int max = -1;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        int val = ch - 'a';

        arr[val]++;
        if (arr[val] > max)
        {
            max = arr[val];
        }
    }

    for(int i = 0; i < 25; i++){
        if(arr[i] == max){
            max = i;
            break;
        }
    }

    char ch = 'a' + max;
    cout << ch;
    return 0;
}