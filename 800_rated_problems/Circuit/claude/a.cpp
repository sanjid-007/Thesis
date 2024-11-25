#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Read 2n switches
    vector<int> switches(2 * n);
    int on_count = 0;
    for(int i = 0; i < 2 * n; i++) {
        cin >> switches[i];
        if(switches[i]) on_count++;
    }
    
    // Calculate minimum lights on
    int min_lights = on_count % 2;  // Unpaired switches after pairing max possible
    
    // Calculate maximum lights on
    // We can pair each ON switch with OFF switch until we run out of either
    int max_lights = min(on_count, 2 * n - on_count);
    // If we have odd number of remaining ON switches, one more light can be ON
    if(on_count > max_lights * 2) {
        max_lights++;
    }
    
    cout << min_lights << " " << max_lights << "\n";
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
