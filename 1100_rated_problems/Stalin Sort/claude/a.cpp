#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Find longest non-increasing subsequence
    vector<int> dp;
    for(int i = 0; i < n; i++) {
        // Find position to insert current element
        auto it = lower_bound(dp.begin(), dp.end(), a[i], greater<int>());
        if(it == dp.end()) {
            dp.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    
    // Minimum removals = array length - longest non-increasing subsequence
    return n - dp.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
    return 0;
}
