#include <bits/stdc++.h>
using namespace std;

void func1(stack<int> &s1, stack<int> &s2)
{
    if (s1.empty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    int val = s1.top();
    s2.push(s1.top());
    s1.pop();

    func1(s1, s2);
    s1.push(val);
}

int main()
{
    stack<int> s1;
    stack<int> s2;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    func1(s1, s2);

    cout << endl;
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }

    cout << endl;

    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    return 0;
}