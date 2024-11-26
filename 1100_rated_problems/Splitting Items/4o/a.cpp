#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.rbegin(), a.rend()); // Sort in descending order
        long long alice = 0, bob = 0;

        // Alice and Bob take turns optimally
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                alice += a[i];
            } else {
                bob += a[i];
            }
        }

        // Minimize Alice's score difference by utilizing k optimally
        for (int i = n - 1; i >= 0 && k > 0; --i) {
            long long increment = min((long long)k, (long long)(a[i] + 1 - a[n - 1]));
            a[i] += increment;
            k -= increment;
        }

        // Recalculate score after adjustment
        alice = 0, bob = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                alice += a[i];
            } else {
                bob += a[i];
            }
        }

        cout << alice - bob << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
