#include <iostream>
using namespace std;

void squareBracket()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << '*' << " ";
        }
        cout << endl;
    }
}

void upperTriangle()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << '*' << " ";
        }
        cout << endl;
    }
}

void printNumberOfJ()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void printNumberOfI()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

void ReverseStars()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 6; j > i; j--)
        {
            cout << 6 - j + 1 << " ";
        }
        cout << endl;
    }
}

void pyramidStars()
{
    int n = 50;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= (n - 1) + i; j++)
        {
            if (i + j >= n - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    pyramidStars();
    return 0;
}