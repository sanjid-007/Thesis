#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Current length of array
    int len = n;
    
    // Keep trying operations while possible
    bool found = true;
    while(found) {
        found = false;
        
        // Try each valid position from right to left
        // (right to left because we want to maximize zeros added)
        for(int i = len; i > 1; i--) {
            // Check if current position satisfies the condition
            if(a[i-1] == len + 1 - i) {
                // Found valid position
                found = true;
                
                // Add i-1 zeros
                int zeros_to_add = i-1;
                len += zeros_to_add;
                
                // Extend array with zeros
                a.resize(len, 0);
                break;
            }
        }
    }
    
    cout << len << "\n";
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
