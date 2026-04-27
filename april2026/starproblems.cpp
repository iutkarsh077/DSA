#include <bits/stdc++.h>
using namespace std;

void RectangleStar(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
}

void Triangle1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
}

void Triangle2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void Triangle3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

void Triangle4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
}

void Triangle5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << j + 1 << ' ';
        }
        cout << endl;
    }
}

void Triangle6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + i; j++)
        {
            if (i + j >= n - 1)
            {
                cout << '*';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}

void Triangle7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ((n * 2) - i - 1); j++)
        {
            if (j < i)
            {
                cout << ' ';
            }
            else
            {
                cout << '*';
            }
        }
        cout << endl;
    }
}

void Diamond(int n)
{
    Triangle6(n);
    Triangle7(n);
}

void Triangle8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
}

void Triangle9(int n)
{
    for (int i = 0; i < n; i++)
    {
        bool isEven = i % 2 == 0 ? true : false;
        for (int j = 0; j <= i; j++)
        {
            if (isEven)
            {
                cout << '1';
            }
            else
            {
                cout << '0';
            }
            isEven = !isEven;
        }
        cout << endl;
    }
}


int main()
{
    Triangle9(10);
    return 0;
}