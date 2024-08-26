#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    int i = 0;

    cout << q.size() << endl;
    cout << "Front is: " << q.front() << endl;
    cout << "Back is: " << q.back();
    cout << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
// while (i < 5)
// {
//     cout << "Enter Your Number: ";
//     int val;
//     cin >> val;
//     q.push(val);
//     i++;
// }