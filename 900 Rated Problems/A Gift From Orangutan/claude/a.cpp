#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort array to access max and min elements easily
    sort(a.begin(), a.end());
    
    // Create optimal arrangement by alternating max and remaining elements
    vector<int> arrangement;
    int left = 0, right = n-1;
    
    // Place largest elements first to maintain high maximum
    while(left <= right) {
        if(left == right) {
            arrangement.push_back(a[left]);
            break;
        }
        arrangement.push_back(a[right]);  // Add largest available
        arrangement.push_back(a[left]);   // Add smallest available
        right--;
        left++;
    }
    
    // Calculate score using the arrangement
    long long score = 0;
    int curr_min = arrangement[0];
    int curr_max = arrangement[0];
    
    for(int i = 0; i < n; i++) {
        curr_min = min(curr_min, arrangement[i]);
        curr_max = max(curr_max, arrangement[i]);
        score += (curr_max - curr_min);
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
