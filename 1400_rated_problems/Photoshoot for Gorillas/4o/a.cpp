#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<int> gorillas(w);
    for (int i = 0; i < w; i++) {
        cin >> gorillas[i];
    }
    sort(gorillas.rbegin(), gorillas.rend()); // Sort heights in descending order
    int max_spectacle = 0;
    for (int i = 0; i < min(k * k, w); i++) {
        max_spectacle += gorillas[i]; // Pick top k*k highest gorillas
    }
    cout << max_spectacle << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
