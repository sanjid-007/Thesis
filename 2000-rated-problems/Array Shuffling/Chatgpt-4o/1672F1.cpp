#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;  // number of test cases
    cin >> t;
    
    while (t--) {
        int n;  // size of the array
        cin >> n;
        
        vector<int> a(n), b(n);
        
        // Read the array a
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Sort array a
        sort(a.begin(), a.end());
        
        // Create array b by shifting the elements of sorted array a by one position
        for (int i = 0; i < n; i++) {
            b[i] = a[(i + 1) % n];  // circularly rotate by one position
        }
        
        // Output array b
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
