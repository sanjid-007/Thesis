#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll b, c, d;
    cin >> b >> c >> d;
    
    // First check if solution is possible
    ll max_or = b;  // Maximum possible value of (a|b) is b
    ll min_and = (c);  // Minimum possible value of (a&c) is 0
    
    // If d > maximum possible difference, no solution exists
    if (d > max_or) {
        cout << -1 << "\n";
        return;
    }
    
    // Try to construct a valid 'a'
    ll a = 0;
    ll needed = d;  // We need (a|b) - (a&c) = d
    
    // For each bit position
    for(int bit = 0; bit <= 60; bit++) {
        ll mask = 1LL << bit;
        
        // Current bit in b and c
        bool b_bit = b & mask;
        bool c_bit = c & mask;
        
        // If b has 1, OR will be 1 regardless of a
        if(b_bit) {
            needed += (c_bit && (a & mask)) ? mask : 0;
        }
        // If b has 0, we can control OR with a
        else {
            if(needed >= mask && !c_bit) {
                a |= mask;  // Set bit in a to 1
                needed -= mask;
            }
        }
    }
    
    // Verify our solution
    if((a|b) - (a&c) == d && a <= (1LL << 61)) {
        cout << a << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
