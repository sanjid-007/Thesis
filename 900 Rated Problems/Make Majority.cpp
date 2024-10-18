#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Faster I/O
    cin.tie(0); // Disable flushing of output buffer after every output
    
    int t; // Number of test cases
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n; // Length of the sequence
        string a;
        cin >> a; // Sequence of 0's and 1's
        
        // Check if there's any '1' in the sequence
        bool has_one = false;
        bool has_zero = false;
        
        // Traverse through the sequence to check if both '1' and '0' are present
        for (char c : a) {
            if (c == '1') has_one = true;
            if (c == '0') has_zero = true;
        }
        
        // If the sequence contains both '1' and '0', it's possible to make a single '1'
        if (has_one && has_zero) {
            cout << "YES\n";
        } else if (has_one) {
            // If the sequence contains only '1's, it's already in the desired form
            cout << "YES\n";
        } else {
            // If the sequence contains only '0's, it's impossible to reduce it to '1'
            cout << "NO\n";
        }
    }
    
    return 0;
}
