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
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + i; j++)
        {
            if (i + j >= n - 1)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void pyramidStarsReverse()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            continue;
        for (int j = 0; j <= ((n - 1) * 2) - i; j++)
        {
            if (j < i)
            {
                continue;
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

void ZeroOnes()
{
    int n = 10;
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

void TajMahal()
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2; j++)
        {
            if (j <= i)
            {
                cout << j + 1 << " ";
            }

            else if (i + j >= (n * 2) - 1)
            {
                cout << (n * 2) - j << " ";
            }
            else
            {
                cout << "_" << " ";
            }
        }
        cout << endl;
    }
}

void CountNumber()
{
    int count = 1;
    int n = 10;
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

void ShowChar()
{
    int n = 26;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            char val = 65 + j;
            cout << val << " ";
        }
        cout << endl;
    }
}

void ShowReversechar()
{
    int n = 20;

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            char val = 65 + (n - j);
            cout << val << " ";
        }
        cout << endl;
    }
}

void OneCharRow()
{
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            char val = 65 + i;
            cout << val << " ";
        }
        cout << endl;
    }
}

void pyramidChars(){
    int n = 5;

    for(int i = 0; i < n; i++){
        int count = 65;
        int val = 1;
        for(int j = 0; j <= (n + i); j++){
            if(i + j < n){
                cout << "_" << ' ';
            }

            else if(i + j >= n && j <= n){
                cout << char(count) << " ";
                count++;
            }
            else{
                cout << char((65 + i) - val) << " ";
                val++;
            }
        }
        cout << endl;
    }
}

void randomCharStart(){
    int n = 26;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << char((65 + (n - 1)) + (j - i)) << ' ';
        }
        cout << endl;
    }
}

void DiamondStars(){
    int n = 10;
    int upperHalf = n / 2;
    int spaces = 0;
    for(int i = 0; i < upperHalf; i++){
        for(int j = 0; j < (n - spaces) / 2; j++){
            cout << '*' << " ";
        }
        for(int j = 0; j < spaces; j++){
            cout << ' ' << " ";
        }

        for(int j = 0; j < (n - spaces) / 2; j++){
            cout << '*' << " ";
        }

        spaces = spaces + 2;
        cout << endl;
    }

    for(int i = 0; i <= upperHalf; i++){
        for(int j = 0; j < (n - spaces) / 2; j++){
            cout << '*' << " ";
        }
        for(int j = 0; j < spaces; j++){
            cout << ' ' << " ";
        }

        for(int j = 0; j < (n - spaces) / 2; j++){
            cout << '*' << " ";
        }

        spaces = spaces - 2;
        cout << endl;
    }
}

void HorizontalX(){
    int n = 8;

    int spaces = (n * 2) - 2;
    int stars = 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < stars/2; j++){
            cout << "*" << " ";
        }

        for(int j = 0; j < spaces; j++){
            cout << "_" << " ";
        }

        for(int j = 0; j < stars/2; j++){
            cout << "*" << " ";
        }

        spaces = spaces - 2;
        stars = stars + 2;
        cout << endl;
    }
    spaces = spaces  + 2;
    stars = stars - 2;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < stars/2; j++){
            cout << "*" << " ";
        }

        for(int j = 0; j < spaces; j++){
            cout << "_" << " ";
        }

        for(int j = 0; j < stars/2; j++){
            cout << "*" << " ";
        }

        spaces = spaces + 2;
        stars = stars - 2;
        cout << endl;
    }
}

void DubaiFrame(){
    int n = 6;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 || i == n - 1){
                cout << "*" << " ";
            }

            else if(j == 0 || j == n - 1){
                cout << "*" << " ";
            }

            else{
                cout << "_" << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    DubaiFrame();
    return 0;
}