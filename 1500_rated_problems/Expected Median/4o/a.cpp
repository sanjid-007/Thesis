#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;

// Function to calculate modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Function to calculate modular inverse
long long mod_inv(long long a, long long mod) {
    return mod_exp(a, mod - 2, mod);
}

// Precompute factorials and inverse factorials
void precompute_factorials(vector<long long>& fact, vector<long long>& inv_fact, int max_n) {
    fact[0] = 1;
    for (int i = 1; i <= max_n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[max_n] = mod_inv(fact[max_n], MOD);
    for (int i = max_n - 1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

// Function to calculate nCk % MOD
long long nCk(int n, int k, const vector<long long>& fact, const vector<long long>& inv_fact) {
    if (k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    int t;
    cin >> t;

    int max_n = 200000;
    vector<long long> fact(max_n + 1), inv_fact(max_n + 1);
    precompute_factorials(fact, inv_fact, max_n);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Sort the array for easier median calculations
        sort(a.begin(), a.end());

        long long result = 0;

        // Find the median contribution for all valid positions
        for (int i = 0; i < n; i++) {
            int left = i, right = n - i - 1;

            // Check if this index can be the median
            if (left >= (k - 1) / 2 && right >= (k - 1) / 2) {
                long long ways_left = nCk(left, (k - 1) / 2, fact, inv_fact);
                long long ways_right = nCk(right, (k - 1) / 2, fact, inv_fact);
                result = (result + a[i] * ways_left % MOD * ways_right % MOD) % MOD;
            }
        }

        cout << result << endl;
    }

    return 0;
}
