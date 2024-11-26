#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, k;
    cin >> n >> k;
    
    // To store minimum operations needed per point
    ll min_ops_per_point = LLONG_MAX;
    
    for(int i = 0; i < n; i++) {
        ll width, height;
        cin >> width >> height;
        
        // For this rectangle:
        // Option 1: Color full columns
        // - Each column needs 'height' operations
        // - Each completed column gives 1 point
        ll ops_per_point_columns = height;
        
        // Option 2: Color full rows
        // - Each row needs 'width' operations
        // - Each completed row gives 1 point
        ll ops_per_point_rows = width;
        
        // Take the minimum of both options
        min_ops_per_point = min(min_ops_per_point, 
                              min(ops_per_point_rows, ops_per_point_columns));
    }
    
    // If we found a valid solution
    if(min_ops_per_point != LLONG_MAX) {
        // Total operations needed = operations per point * points needed
        ll total_ops = min_ops_per_point * k;
        
        // Check if the total operations would overflow
        if(total_ops / k != min_ops_per_point) {
            cout << -1 << "\n";
        } else {
            cout << total_ops << "\n";
        }
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
