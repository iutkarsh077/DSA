#include <bits/stdc++.h>
using namespace std;

class Palidrome
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        string ans = "";
        while (i < s.size())
        {
            if (isalnum(s[i]))
            {
                ans += tolower(s[i]);
            }
            i++;
        }

        i = 0;
        while (i < ans.size())
        {
            if (ans[i] != ans[ans.size() - 1 - i])
            {
                return false;
            }
            i++;
        }

        return true;
    }
};

int main()
{
    return 0;
}