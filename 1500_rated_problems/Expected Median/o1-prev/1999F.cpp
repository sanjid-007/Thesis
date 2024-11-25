#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;
const int MAXN = 200005;

ll fact[MAXN], invfact[MAXN];

ll power(ll x, ll y) {
    ll res = 1;
    x %= MOD;
    while(y > 0) {
        if(y % 2)
            res = res * x % MOD;
        x = x * x % MOD;
        y /= 2;
    }
    return res;
}

void init() {
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
    for(int i = MAXN - 2; i >= 1; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
}

ll C(int n, int k) {
    if(k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int o = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            o += a[i];
        }
        int z = n - o;
        ll total = C(n, k);
        if(k > n) {
            total = 0;
        }
        int m = (k + 1) / 2;
        ll sum_terms = 0;
        for(int i = 0; i < m; i++) {
            if(i > o || k - i > z) continue;
            ll term = C(o, i) * C(z, k - i) % MOD;
            sum_terms = (sum_terms + term) % MOD;
        }
        ll ans = (total - sum_terms + MOD) % MOD;
        cout << ans << '\n';
    }
    return 0;
}
