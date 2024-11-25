#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    
    // Read initial order
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Create position map to quickly find where each member is in line
    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++) {
        pos[a[i]] = i;
    }
    
    // Read required presenters
    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    
    // For each presenter, check if anyone they need later is ahead of them
    bool possible = true;
    int lastPos = -1;  // Keep track of the rightmost position we've used
    
    for(int i = 0; i < m; i++) {
        int currentPresenter = b[i];
        int currentPos = pos[currentPresenter];
        
        // If this presenter is ahead of someone we've already used
        if(currentPos < lastPos) {
            possible = false;
            break;
        }
        
        // Look ahead to see if we need anyone before current position
        for(int j = i + 1; j < m; j++) {
            int futurePresenter = b[j];
            int futurePos = pos[futurePresenter];
            
            // If we need someone who's ahead of current presenter
            if(futurePos < currentPos) {
                possible = false;
                break;
            }
        }
        
        if(!possible) break;
        lastPos = max(lastPos, currentPos);
    }
    
    cout << (possible ? "YA" : "TIDAK") << "\n";
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
