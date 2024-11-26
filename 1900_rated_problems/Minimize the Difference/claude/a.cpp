#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // For n=1, no operations possible
    if(n == 1) {
        cout << "0\n";
        return;
    }
    
    // Key observation: For any three consecutive elements,
    // we can make the middle element closer to both ends
    // by moving values appropriately
    
    ll ans = LLONG_MAX;
    
    // Try different possibilities for min and max elements
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            // Try keeping elements i and j as potential min/max
            vector<ll> b = a;
            
            // Process elements between i and j
            for(int k = i; k < j; k++) {
                // Move excess values forward
                ll diff = max(0LL, b[k] - b[i]);
                b[k] -= diff;
                b[k+1] += diff;
            }
            
            // Process elements after j
            for(int k = j; k < n-1; k++) {
                // Move excess values forward
                ll diff = max(0LL, b[k] - b[j]);
                b[k] -= diff;
                b[k+1] += diff;
            }
            
            // Find min and max in the resulting array
            ll mn = *min_element(b.begin(), b.end());
            ll mx = *max_element(b.begin(), b.end());
            ans = min(ans, mx - mn);
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
