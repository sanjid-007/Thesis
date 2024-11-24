#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll n, m, k;
        cin >> n >> m >> k;
        ll w;
        cin >> w;
        vector<ll> a(w);
        for (int i = 0; i < w; ++i) {
            cin >> a[i];
        }

        // Calculate t_row and frequencies
        map<ll, ll> freq_row;
        if (n < k) {
            for (ll i = 1; i <= n; ++i) {
                freq_row[0]++;
            }
        } else {
            for (ll i = 1; i <= n; ++i) {
                ll t;
                if (i < k)
                    t = i;
                else if (i <= n - k + 1)
                    t = k;
                else
                    t = n - i + 1;
                freq_row[t]++;
            }
        }

        // Calculate t_col and frequencies
        map<ll, ll> freq_col;
        if (m < k) {
            for (ll j = 1; j <= m; ++j) {
                freq_col[0]++;
            }
        } else {
            for (ll j = 1; j <= m; ++j) {
                ll t;
                if (j < k)
                    t = j;
                else if (j <= m - k + 1)
                    t = k;
                else
                    t = m - j + 1;
                freq_col[t]++;
            }
        }

        // Calculate counts c and their frequencies
        map<ll, ll> freq_c;
        for (auto &fr : freq_row) {
            ll t_row = fr.first;
            ll freq_r = fr.second;
            for (auto &fc : freq_col) {
                ll t_col = fc.first;
                ll freq_c_col = fc.second;
                ll c = t_row * t_col;
                freq_c[c] += freq_r * freq_c_col;
            }
        }

        // Sort counts c in decreasing order
        vector<pair<ll, ll>> counts;
        for (auto &p : freq_c) {
            counts.emplace_back(p.first, p.second);
        }
        sort(counts.rbegin(), counts.rend());

        // Sort gorilla heights in decreasing order
        sort(a.rbegin(), a.rend());

        ll total_spectacle = 0;
        ll idx = 0; // index in gorillas
        for (auto &p : counts) {
            ll c = p.first;
            ll freq = p.second;
            while (freq > 0 && idx < w) {
                total_spectacle += a[idx] * c;
                idx++;
                freq--;
            }
            if (idx >= w)
                break;
        }
        cout << total_spectacle << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
