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

void halfDiamondStar()
{
    int n = 5;

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i + j <= 2 * n - 2)
            {
                cout << "*";
            }
        }

        cout << endl;
    }
}

void NumberRightTriangle()
{
    int n = 8;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

void TombStructure()
{
    int n = 7;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
        }

        for (int j = i + 1; j < (2 * n) - i - 1; j++)
        {
            cout << " ";
        }

        for (int j = (2 * n) - i - 1; j <= 2 * n - 1; j++)
        {
            cout << 2 * n - j;
        }

        cout << endl;
    }
}

void RightTriangleNumber2()
{
    int n = 10;
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}

void RightTriangleAlphabet()
{
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << char(65 + j);
        }
        cout << endl;
    }
}

void ReverseRightTriangleAlphabet()
{
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << char(65 + j);
        }

        cout << endl;
    }
}

void aba()
{
    int n = 8;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << char(65 + j);
        }

        for (int j = i - 1; j >= 0; j--)
        {
            cout << char(65 + j);
        }

        cout << endl;
    }
}

void EAlphabet()
{
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << char(((65 + n - 1) - i) + j);
        }

        cout << endl;
    }
}

void VerticalDiamond()
{
    int n = 10;
    // Upper half
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < i * 2; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Lower Half
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < (n * 2) - (i * 2) - 2; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void ButterFly()
{
    int n = 10;
    // Upper half
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < (n * 2) - (i * 2) - 2; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Lower Half
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        for (int j = 0; j < i * 2; j++)
        {
            cout << " ";
        }

        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void HollowRectangle(){
    int n = 100;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || j == 0 || j == n - 1 || i == n - 1){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

void gcd(){
    int a = 40;
    int b = 20;
    int mini = min(a, b);

    while(mini > 0){
        if(a % mini == 0 && b % mini == 0){
            cout << mini;
            break;
        }
        mini = mini - 1;
    }
}

void allDivisor(){
    int n = 36;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cout << i << " ";
        }
    }
}

int main()
{
    allDivisor();
    return 0;
}