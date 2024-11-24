#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll t, n, k;
vector<ll> a;
vector<ll> prefix_sum;

bool is_possible(ll m, ll n, ll k, vector<ll>& a, vector<ll>& prefix_sum) {
    // Compute D_max
    ll total_cards = 0;
    for (ll ai : a) total_cards += ai;
    total_cards += k;
    ll D_max = total_cards / m;
    if (D_max == 0) return false;

    ll left = 1, right = D_max, ans = 0;
    while (left <= right) {
        ll D = (left + right) / 2;
        // Compute sum of min(a_i, D)
        ll idx = lower_bound(a.begin(), a.end(), D) - a.begin();
        ll S1 = 0;
        if (idx > 0) S1 += prefix_sum[idx - 1];
        S1 += D * (n - idx);
        ll required_additional = D * m - S1;
        if (required_additional <= k) {
            ans = D;
            left = D + 1;
        } else {
            right = D - 1;
        }
    }
    return ans > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n);
        for (ll i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        prefix_sum.resize(n);
        prefix_sum[0] = a[0];
        for (ll i = 1; i < n; ++i)
            prefix_sum[i] = prefix_sum[i - 1] + a[i];
        ll left = 1, right = n, ans = 0;
        while (left <= right) {
            ll m = (left + right) / 2;
            if (is_possible(m, n, k, a, prefix_sum)) {
                ans = m;
                left = m + 1;
            } else {
                right = m - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
