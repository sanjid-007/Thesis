#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long ll;

bool isValid(ll deckSize, const vector<ll>& a, ll n, ll k) {
    ll needed = 0;
    for (ll count : a) {
        needed += max(0LL, deckSize - count);
        if (needed > k) return false;
    }
    return needed <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll low = 1, high = n + k, answer = 1;
        while (low <= high) {
            ll mid = (low + high) / 2;
            if (isValid(mid, a, n, k)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
