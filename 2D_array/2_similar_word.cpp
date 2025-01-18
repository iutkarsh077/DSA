#include <iostream>
#include <string>

using namespace std;

bool isSubstringPresent(string s) {
    int n = s.length();
    for (int i = 0; i < n - 1; i++) {
        string val = s.substr(i, 2);
        
        for (int j = n - 1; j >= i + 1; j--) { // Adjusted the loop condition
            string valdup = s.substr(j, 1) + s.substr(j - 1, 1); // Concatenate characters in reverse order
            cout << "valdup is: " << valdup << endl;
            if (val == valdup) {
                return true;
            }
        }
    }
    return false;


}

int main() {
    string input = "abcd";
    cout << boolalpha << isSubstringPresent(input) << endl; // Output: false
    return 0;
}
