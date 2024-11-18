#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int MAX_A = 1000006;
const int MOD = 998244353;
typedef long long ll;

vector<int> spf(MAX_A); // Smallest prime factor

void sieve() {
    for (int i = 2; i < MAX_A; ++i) {
        if (spf[i] == 0) {
            for (int j = i; j < MAX_A; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
}

// Function to factorize a number into its prime factors
vector<int> get_primes(int x) {
    vector<int> res;
    while (x > 1) {
        int p = spf[x];
        res.push_back(p);
        while (x % p == 0) x /= p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();

    int n;
    cin >> n;
    vector<int> a(n + 1); // 1-based indexing
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<ll> dp(n + 1, 0);
    dp[1] = 1;

    // Map from prime to list of positions where the prime divides a_i
    unordered_map<int, int> last_pos; // last position where prime p divides a_j
    for (int i = 1; i <= n; ++i) {
        vector<int> primes = get_primes(a[i]);
        dp[i] = 0;
        if (i == 1) dp[i] = 1;
        else {
            for (int p : primes) {
                if (last_pos.count(p)) {
                    int j = last_pos[p];
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }
        }
        // Update last positions for primes dividing a_i
        for (int p : primes) {
            last_pos[p] = i;
        }
    }

    cout << dp[n] % MOD << '\n';
    return 0;
}
