#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ccdbzcbcd";
    map<char, int> mp;
    int max_len = 0;
    int n = s.size();
    int l = 0;
    int r = 0;
    for (int r = 0; r < n; r++)
    {
        char val = s[r];

        if (mp.find(val) != mp.end() && mp[val] >= l)
        {
            l = mp[val] + 1;
        }

        mp[val] = r;

        max_len = max(max_len, r - l + 1);
    }

    cout << max_len;
    return 0;
}

/* map<char, int> mp;
 int max_len = 0;
 int n = s.size();

 for(int i = 0; i < n; i++){
     mp.clear();
     int len = 0;

     for(int j = i; j < n; j++){
         char val = s[j];
         auto a = mp.find(val);
         if(a != mp.end()){
             break;
         } else {
             mp[val] = 1;
             len++;
         }
     }
     max_len = max(len, max_len);

 }
 cout << max_len;*/
