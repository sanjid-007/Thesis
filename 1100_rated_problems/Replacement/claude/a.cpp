#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, r;
    cin >> s >> r;
    
    // Count adjacent different bits
    int diff_count = 0;
    for(int i = 0; i < n-1; i++) {
        if(s[i] != s[i+1]) diff_count++;
    }
    
    // Need exactly n-1 operations
    // Each operation requires one pair of different bits
    cout << (diff_count == n-1 ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
