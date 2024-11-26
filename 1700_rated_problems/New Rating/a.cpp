#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Keep track of maximum rating achievable by including elements up to index i
    vector<int> prefix_max(n + 1, 0);
    int rating = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > rating) rating++;
        else if(a[i] < rating) rating--;
        prefix_max[i + 1] = rating;
    }
    
    // Keep track of maximum rating achievable from index i to end
    vector<int> suffix_max(n + 1, 0);
    rating = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] > rating) rating++;
        else if(a[i] < rating) rating--;
        suffix_max[i] = rating;
    }
    
    int ans = 0;
    // For each possible starting point of skip interval
    for(int i = 0; i < n; i++) {
        // The rating we achieved up to i
        int before = (i > 0) ? prefix_max[i] : 0;
        
        // Try all possible ending points
        for(int j = i; j < n; j++) {
            // After skipping [i,j], start with rating 'before'
            // and add contribution from remaining elements
            rating = before;
            if(j + 1 < n) {
                int after = suffix_max[j + 1];
                // Adjust suffix contribution based on 'before' rating
                while(rating < after && j + 1 < n) {
                    rating++;
                }
            }
            ans = max(ans, rating);
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << '\n';
    }
    return 0;
}
