#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll computeXOR(ll n) {
    if (n < 0) return 0;
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0;
}

ll rangeXOR(ll l, ll r) {
    return computeXOR(r) ^ computeXOR(l - 1);
}

ll solveQuery(ll l, ll r, int i, ll k) {
    ll mod = 1LL << i;
    ll xorResult = 0;

    if (l > r) return 0;
    for (ll start = l; start <= r;) {
        ll startGroup = start / mod;
        ll endGroup = r / mod;
        ll groupStart = startGroup * mod;
        ll groupEnd = groupStart + mod - 1;

        if (startGroup == endGroup) {
            for (ll x = start; x <= r; ++x) {
                if (x % mod != k) xorResult ^= x;
            }
            break;
        }

        if (start % mod != k) {
            for (ll x = start; x < min(r + 1, groupEnd + 1); ++x) {
                if (x % mod != k) xorResult ^= x;
            }
        }

        start = groupEnd + 1;
    }
    return xorResult;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll l, r, k;
        int i;
        cin >> l >> r >> i >> k;
        cout << solveQuery(l, r, i, k) << '\n';
    }

    return 0;
}
