#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPossible(ll d, vector<ll>& a, ll n, ll k) {
    if (d > n) return false;  // deck size can't be larger than distinct numbers
    
    ll total_cards = accumulate(a.begin(), a.end(), 0LL) + k;
    if (total_cards % d != 0) return false;  // total cards must be divisible by deck size
    
    ll decks = total_cards / d;  // number of decks needed
    ll extra_needed = 0;
    
    // For each number, we need at most 'decks' copies
    // Calculate how many extra cards we need to buy
    for (int i = 0; i < n; i++) {
        if (a[i] > decks) return false;  // can't use all cards if some number appears too many times
        extra_needed += max(0LL, decks - a[i]);
    }
    
    return extra_needed <= k;  // check if we have enough coins to buy needed cards
}

int solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll left = 1, right = n;
    ll answer = 1;
    
    // Binary search on deck size
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (isPossible(mid, a, n, k)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}
