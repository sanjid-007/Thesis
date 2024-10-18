#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Faster I/O
    cin.tie(0); // Disable flushing of output buffer after every output
    
    int t; // Number of test cases
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Read the initial array
        }
        
        int max_val = *max_element(a.begin(), a.end()); // Initial maximum value
        
        for (int i = 0; i < m; i++) {
            char op; 
            int l, r;
            cin >> op >> l >> r;
            
            // Apply the operation
            for (int j = 0; j < n; j++) {
                if (a[j] >= l && a[j] <= r) {
                    if (op == '+') {
                        a[j]++; // Increment
                    } else {
                        a[j]--; // Decrement
                    }
                }
            }
            
            // Update the maximum value after the operation
            max_val = *max_element(a.begin(), a.end());
            
            // Output the current maximum value
            cout << max_val << " ";
        }
        
        cout << endl; // Move to the next test case
    }
    
    return 0;
}
