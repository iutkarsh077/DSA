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
        if(i == 0) continue;
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

void ZeroOnes(){
    int n = 10;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if((i + j) % 2 == 0){
                cout << 1 << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

void TajMahal(){
    int n = 10;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 2; j++){
            if(j <= i){
                cout << j + 1 << " ";
            }

            else if(i + j >= (n * 2) - 1){
                cout << (n * 2) - j << " ";
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
    TajMahal();
    return 0;
}