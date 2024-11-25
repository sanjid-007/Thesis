#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    // For each position, try keeping it as is and see if we can make rest ascending
    int ans = n;  // worst case: change all elements
    for(int i = 0; i < n; i++) {
        int cur = i;  // count of changes needed
        int prev = h[i];  // previous element in ascending sequence
        
        // Check elements before position i
        for(int j = i-1; j >= 0; j--) {
            if(h[j] > prev) {
                cur++;
            }
        }
        
        // Check elements after position i
        prev = h[i];
        for(int j = i+1; j < n; j++) {
            if(h[j] < prev) {
                cur++;
                prev = h[j-1];  // use previous valid element
            } else {
                prev = h[j];
            }
        }
        
        ans = min(ans, cur);
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
