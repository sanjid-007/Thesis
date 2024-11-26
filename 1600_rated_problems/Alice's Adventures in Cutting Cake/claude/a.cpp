#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Function to check if we can make m segments with sum >= v
// excluding the segment [l,r]
bool check(vector<ll>& psum, int n, int m, ll v, int l, int r) {
    int pieces = 0;
    ll curr = 0;
    
    // Try segments before l
    for(int i = 0; i < l; i++) {
        curr += psum[i] - (i > 0 ? psum[i-1] : 0);
        if(curr >= v) {
            pieces++;
            curr = 0;
        }
    }
    
    // Try segments after r
    curr = 0;
    for(int i = r+1; i < n; i++) {
        curr += psum[i] - (i > 0 ? psum[i-1] : 0);
        if(curr >= v) {
            pieces++;
            curr = 0;
        }
    }
    
    return pieces >= m;
}

void solve() {
    int n, m, v;
    cin >> n >> m >> v;
    
    vector<ll> a(n), psum(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Calculate prefix sums
    psum[0] = a[0];
    for(int i = 1; i < n; i++) {
        psum[i] = psum[i-1] + a[i];
    }
    
    ll ans = -1;
    
    // Try empty piece for Alice
    if(check(psum, n, m, v, -1, -1)) {
        ans = 0;
    }
    
    // Try each possible segment for Alice using sliding window
    for(int len = 1; len <= n; len++) {
        for(int start = 0; start + len - 1 < n; start++) {
            int end = start + len - 1;
            ll alice_piece = psum[end] - (start > 0 ? psum[start-1] : 0);
            
            if(check(psum, n, m, v, start, end)) {
                ans = max(ans, alice_piece);
            }
        }
    }
    
    cout << ans << "\n";
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
