#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a;
    cin >> a;
    cout << int(a) << " " << a << endl;
    if (int(a) >= 97 && int(a) <= 122)
    {
        cout << "This is a smaller char";
    }

    else if (int(a) >= 65 && int(a) <= 90)
    {
        cout << "This is a Bigger Char";
    }
    else if(int(a) >= 48 && int(a) <= 57){
        cout << "This is a Number";
    }
    return 0;
}