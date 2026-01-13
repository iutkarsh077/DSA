#include <bits/stdc++.h>
using namespace std;

void RectangleStar()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void RightTriangle()
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void RightTriangleNumber()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void RightTriangleNumberI()
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

void ReverseRightTriangleStar()
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void ReverseRightTriangleNumber()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

void UpperPyramid()
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (i + j < n - 1)
            {
                cout << " ";
            }
        }

        for (int j = n - i - 1; j < n + i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void ReversePyramid()
{
    int n = 7;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int j = i; j <= (2 * n - 2) - i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void DiamondStar()
{
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (i + j < n - 1)
            {
                cout << " ";
            }
        }

        for (int j = n - i - 1; j < n + i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int j = i; j <= (2 * n - 2) - i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void halfDiamondStar(){
    int n = 5;

    for(int i = 0; i < 2 * n - 1; i++){
        for(int j = 0; j <= i; j++){
            if(i + j <= 2 * n - 2){
                cout << "*";
            }
        }

        cout << endl;
    }
}

int main()
{
    halfDiamondStar();
    return 0;
}