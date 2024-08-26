#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    vector<int> arr;
    arr = {1, 2, 3, 4, 5, 5, 2, 1, 3, 4};
    set<int> s1;
    for (int i = 0; i < arr.size(); i++)
    {
        s1.insert(arr[i]);
    }


    cout << s1.size();
    // for (auto i = s1.begin(); i != s1.end(); i++)
    // {
    //     cout << *i << " ";
    // }
    return 0;
}

// arr.erase(arr.begin() + 1);
// arr.clear();

// if(arr.size() == 0){
//     cout << "Array is empty";
// }
// int i = 0;
// while(i < arr.size()){
//     cout << arr[i] << " ";
//     i++;
// }
// cout << "Index 1 is: " << arr[1];