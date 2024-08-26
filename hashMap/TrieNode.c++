#include <bits/stdc++.h>
using namespace std;

class TriNode
{
public:
    char data;
    TriNode *children[26];
    bool isTerminal;

    TriNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isTerminal = false;
    }
};

int main()
{
    return 0;
}