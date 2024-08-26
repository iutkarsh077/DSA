/*#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 1, 7, 5, 8, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
*/

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 1, 7, 5, 8, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1, j, temp; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
