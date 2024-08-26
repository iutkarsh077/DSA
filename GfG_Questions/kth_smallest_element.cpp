#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*int smallest_element(int arr[], int n, int k)
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);

    return arr[k - 1];
}*/

int main()
{
    int arr[6] = {7, 10, 4, 3, 20, 15};
    vector<int> v1(arr + 0, arr + 6);
    int i = 0;
    while(i < v1.size()){
        cout << v1[i] << " ";
        i++;
    }
    return 0;
}