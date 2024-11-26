#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

// Calculate nCr % MOD
ll nCr(ll n, ll r) {
    if (r > n) return 0;
    vector<ll> fact(n + 1, 1);
    vector<ll> invFact(n + 1, 1);
    
    // Calculate factorials
    for(int i = 2; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    // Calculate modular multiplicative inverse using fast power
    auto power = [&](ll base, ll exp) {
        ll result = 1;
        while(exp > 0) {
            if(exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    };
    
    invFact[n] = power(fact[n], MOD-2);
    for(int i = n-1; i >= 0; i--) {
        invFact[i] = (invFact[i+1] * (i+1)) % MOD;
    }
    
    return (((fact[n] * invFact[r]) % MOD) * invFact[n-r]) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int ones = 0;
    
    // Count total number of 1s in array
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ones += a[i];
    }
    
    // Calculate required 1s for median to be 1
    int reqOnes = (k + 1) / 2;
    ll ans = 0;
    
    // For each possible count of 1s from reqOnes to min(k, ones)
    for(int i = reqOnes; i <= min(k, ones); i++) {
        // Choose i ones from total ones
        // and (k-i) zeros from total zeros
        ll ways = nCr(ones, i);
        ways = (ways * nCr(n - ones, k - i)) % MOD;
        ans = (ans + ways) % MOD;
    }
    
    cout << ans << "\n";
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
