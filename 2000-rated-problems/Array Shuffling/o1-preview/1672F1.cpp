#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;

    if (n == 1) {
        b = a;
    } else if (n == 2) {
        if (a[0] != a[1]) {
            b = {a[1], a[0]};
        } else {
            b = a;
        }
    } else {
        vector<int> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());
        int shift = n / 2;
        for (int i = 0; i < n; ++i) {
            b[i] = sorted_a[(i + shift) % n];
        }
        // Check for positions where b[i] == a[i] and swap if necessary
        for (int i = 0; i < n; ++i) {
            if (b[i] == a[i]) {
                swap(b[i], b[(i + 1) % n]);
            }
        }
    }

    for (int x : b) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
