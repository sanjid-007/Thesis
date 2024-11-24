#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> L(n + 1), R(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            L[i] = i - (a[i] - 1);
            R[i] = i + (a[i] - 1);
        }
        int L_max = L[1], R_min = R[1];
        for (int i = 1; i <= n; ++i) {
            L_max = max(L_max, L[i]);
            R_min = min(R_min, R[i]);
        }
        int ans = max(0, min(n, R_min) - max(1, L_max) + 1);
        cout << ans << '\n';
    }
    return 0;
}
