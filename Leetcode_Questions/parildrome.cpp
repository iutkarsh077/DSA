using namespace std;
#include <bits/stdc++.h>

/*
int main(){
    int x = 121;
    string y = to_string(x);
}
*/

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return (b, a % b);
}
int main()
{
    int val = gcd(18, 12);
    cout << val << endl;
    int lcm = (18 * 12) / val;
    cout << lcm;
}