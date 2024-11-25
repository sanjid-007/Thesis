#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort in descending order
    sort(a.rbegin(), a.rend());
    
    ll cost = 0;
    ll score = 0;
    
    // Handle pairs
    for(int i = 0; i < n-1; i += 2) {
        // Cost to make current pair equal
        ll diff = a[i] - a[i+1];
        if(cost + diff <= k) {
            cost += diff;
            a[i+1] = a[i];
        } else {
            // Can't make them equal, calculate partial increase
            ll remaining = k - cost;
            a[i+1] += remaining;
            cost = k;
            break;
        }
    }
    
    // Calculate final score
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) score += a[i];
        else score -= a[i];
    }
    
    cout << score << "\n";
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
