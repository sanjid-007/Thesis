#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Read n and sequence a
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // Compute prefix sums of a
    vector<ll> pre_a(n + 1, 0);
    for (int i = 1; i <= n; ++i) pre_a[i] = pre_a[i - 1] + a[i];

    // Compute prefix sums of pre_a
    vector<ll> pre_pre_a(n + 1, 0);
    for (int i = 1; i <= n; ++i) pre_pre_a[i] = pre_pre_a[i - 1] + pre_a[i];

    // Compute cnt array
    vector<ll> cnt(n + 1, 0);
    for (int i = 1; i <= n; ++i) cnt[i] = cnt[i - 1] + (n - i + 1);

    // Compute sum_i and S_sum arrays
    vector<ll> sum_i(n + 1, 0);
    vector<ll> S_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        sum_i[i] = (pre_pre_a[n] - pre_pre_a[i - 1]) - (n - i + 1) * pre_a[i - 1];
        S_sum[i] = S_sum[i - 1] + sum_i[i];
    }

    // Function to compute sumb_p
    auto compute_sumb_p = [&](ll p) -> ll {
        if (p == 0) return 0;
        int i = lower_bound(cnt.begin(), cnt.end(), p) - cnt.begin();
        if (i > 0 && cnt[i - 1] >= p) i--;
        ll S = S_sum[i - 1];
        ll p_in_i = p - cnt[i - 1];
        ll j = i + p_in_i - 1;
        ll sumb_i_p = (pre_pre_a[j] - pre_pre_a[i - 1]) - (j - i + 1) * pre_a[i - 1];
        ll sumb_p = S + sumb_i_p;
        return sumb_p;
    };

    // Read number of queries
    int q;
    cin >> q;
    while (q--) {
        ll l_i, r_i;
        cin >> l_i >> r_i;
        ll sumb_r = compute_sumb_p(r_i);
        ll sumb_l = compute_sumb_p(l_i - 1);
        ll ans = sumb_r - sumb_l;
        cout << ans << '\n';
    }

    return 0;
}
