#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // dp[i] represents maximum number of beautiful segments that can be formed
    // considering array from index i to n-1
    vector<int> dp(n + 1, 0);
    
    // Start filling dp from right to left
    for(int i = n-1; i >= 0; i--) {
        // Initialize with the best we can do by skipping current element
        dp[i] = dp[i+1];
        
        // Try all possible segments starting at i
        long long sum = 0;
        for(int j = i; j < n; j++) {
            sum += a[j];
            // If we found a beautiful segment [i,j]
            if(sum == 0) {
                // Either use this segment and solve for remaining array after j+1
                dp[i] = max(dp[i], 1 + dp[j+1]);
            }
        }
    }
    
    cout << dp[0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
