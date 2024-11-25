#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Function to calculate square of distance between two points
ll dist2(ll x1, ll y1, ll x2, ll y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<ll,ll>> circles(n);
    
    // Read circle centers
    for(int i = 0; i < n; i++) {
        cin >> circles[i].first >> circles[i].second;
    }
    
    ll xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    
    // Calculate square of distance to target
    ll dist_to_target = dist2(xs, ys, xt, yt);
    
    // Check distance to each circle center
    for(int i = 0; i < n; i++) {
        ll dist_to_circle = dist2(xs, ys, circles[i].first, circles[i].second);
        ll target_to_circle = dist2(xt, yt, circles[i].first, circles[i].second);
        
        // Key observation: If circle center is closer to start or end point
        // than our path length, we can never make it
        if(4 * dist_to_circle <= dist_to_target || 
           4 * target_to_circle <= dist_to_target) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
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
