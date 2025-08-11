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

void upperTriangle(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j <= i; j++){
            cout << '*' << " ";
        }
        cout << endl;
    }
}

void printNumberOfJ(){
    for(int i = 0; i < 6; i++){
        for(int j = 0; j <= i; j++){
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

int main()
{
    printNumberOfJ();
    return 0;
}