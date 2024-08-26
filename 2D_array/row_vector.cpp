#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> vec = {
        {0, 1, 2, 3, 9},
        {1, 2, 3, 4, 4},
        {2, 3, 4, 5, 4},
        {3, 4, 5, 6, 6}
    };

    int rows = vec.size(); // Number of rows
    int cols = vec[0].size(); // Number of columns

    cout << "Rows: " << rows << endl;
    cout << "Columns: " << cols << endl;

    return 0;
}
