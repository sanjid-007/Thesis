#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, b, c;
    cin >> n >> b >> c;
    
    // Special case for n = 1
    if(n == 1) {
        if(c == 0) cout << "0\n";
        else cout << "1\n";
        return;
    }
    
    // If b = 0, all elements are c
    if(b == 0) {
        if(c >= n) cout << "1\n";
        else if(c < n && n > 1) cout << "-1\n";
        return;
    }
    
    // Check if already a permutation
    // For arithmetic sequence ai = b*(i-1) + c to be a permutation:
    // 1. b must be 1
    // 2. c must be 0
    // 3. Or some other very specific cases
    if(b == 1 && c < n && c >= 0) {
        bool isPerm = true;
        for(ll i = 0; i < n; i++) {
            if(b * i + c >= n) {
                isPerm = false;
                break;
            }
        }
        if(isPerm) {
            cout << "0\n";
            return;
        }
    }
    
    // For very large n, if b is also large
    // Most elements will be >= n
    // We need at least n-1 numbers to be < n for a permutation
    ll first_ge_n = LLONG_MAX;  // First index where value >= n
    if(b > 0) {
        // Find first index where value >= n
        // b*i + c >= n
        // i >= (n-c)/b
        first_ge_n = max(0LL, (n - c + b - 1) / b);
    }
    
    if(first_ge_n >= n) {
        // All elements are < n
        // Check if they form permutation
        set<ll> unique_vals;
        for(ll i = 0; i < n; i++) {
            unique_vals.insert(b * i + c);
        }
        if(unique_vals.size() == n && *unique_vals.rbegin() < n) {
            cout << "0\n";
            return;
        }
    }
    
    // Count numbers >= n and unique numbers < n
    ll count_ge_n = n - first_ge_n;
    if(count_ge_n < 0) count_ge_n = 0;
    
    set<ll> uniqueLessN;
    for(ll i = 0; i < min(n, first_ge_n); i++) {
        ll val = b * i + c;
        if(val < n) uniqueLessN.insert(val);
    }
    
    // If we have too many large numbers, impossible
    if(count_ge_n > n - uniqueLessN.size()) {
        cout << "-1\n";
        return;
    }
    
    // Each operation will introduce one missing number < n
    // We need exactly n numbers from 0 to n-1
    // Each operation reduces one number >= n and adds one missing number < n
    ll missing_count = n - uniqueLessN.size();
    
    // If count_ge_n is exactly equal to missing_count
    // Then we need exactly count_ge_n operations
    if(count_ge_n >= missing_count) {
        cout << missing_count << "\n";
        return;
    }
    
    cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
