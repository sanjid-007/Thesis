#include <bits/stdc++.h>
using namespace std;

// Function to query gcd(x + a, x + b)
int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int result;
    cin >> result;
    return result;
}

// Function to solve a single test case
void solve() {
    int gcd_value = 0;
    // Query with increasing large values to gather gcd information
    for (int i = 1; i <= 30; ++i) {
        int a = i * 1000000000;  // We use large numbers for the query
        int b = (i + 1) * 1000000000;  // Ensure a != b
        int result = query(a, b);
        gcd_value = gcd(gcd_value, result); // Use the gcd results
    }
    
    // Output the final guess for x
    cout << "! " << gcd_value << endl;
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

