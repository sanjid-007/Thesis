#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_PRIME = 23; // We will test primes up to 23

vector<int> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23};

void solve() {
    vector<int> factors;
    // Step 1: Identify small prime factors of x
    for (int p : small_primes) {
        cout << "? 0 " << p << endl;
        cout.flush();
        int d;
        cin >> d;
        if (d == p) {
            factors.push_back(p);
        }
    }
    // Compute P = product of factors
    ll P = 1;
    for (int p : factors) {
        P *= p;
    }
    // If P is 1, x is likely to be prime or has large prime factors
    if (P == 1) {
        P = 1;
    }
    // Generate candidate x's
    vector<ll> candidates;
    for (ll x = P; x <= 1e9; x += P) {
        candidates.push_back(x);
    }
    // Step 2: Eliminate candidates using additional queries
    while (candidates.size() > 1) {
        ll a = rand() % (int)(1e9) + 1;
        ll k = rand() % (int)(1e9) + 1;
        cout << "? " << a << " " << a + k << endl;
        cout.flush();
        int d;
        cin >> d;
        vector<ll> new_candidates;
        for (ll x : candidates) {
            ll expected_d = __gcd(x + a, k);
            if (expected_d == d) {
                new_candidates.push_back(x);
            }
        }
        candidates = new_candidates;
        if (candidates.size() == 0) {
            // Should not happen
            break;
        }
    }
    // Output the answer
    cout << "! " << candidates[0] << endl;
    cout.flush();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
