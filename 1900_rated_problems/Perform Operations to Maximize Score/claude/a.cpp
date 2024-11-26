#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> solve(ll n) {
    vector<ll> sequence;
    
    // Find the smallest number that has some bits set from n
    // This will be our starting number
    ll first = n & (-n);  // Gets least significant set bit
    sequence.push_back(first);
    
    ll current = first;
    while (true) {
        // Find next valid number
        ll next = current + 1;
        while (next <= n) {
            // Check if this number forms valid pair with current
            if ((current | next) == n && next > current) {
                sequence.push_back(next);
                current = next;
                break;
            }
            next++;
        }
        
        // If we couldn't find next number, break
        if (next > n) break;
    }
    
    return sequence;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        
        vector<ll> result = solve(n);
        
        // Output length
        cout << result.size() << "\n";
        
        // Output sequence
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
