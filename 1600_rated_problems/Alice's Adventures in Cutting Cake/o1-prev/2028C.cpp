#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll processLeftToRight(int n, int m, ll v, vector<int>& a, ll total_sum) {
    int idx = 0;
    ll sum_assigned = 0;
    for (int creature = 0; creature < m; ++creature) {
        ll sum = 0;
        while (idx < n && sum < v) {
            sum += a[idx];
            ++idx;
        }
        if (sum >= v) {
            sum_assigned += sum;
        } else {
            return -1;
        }
    }
    return total_sum - sum_assigned;
}

ll processRightToLeft(int n, int m, ll v, vector<int>& a, ll total_sum) {
    int idx = n - 1;
    ll sum_assigned = 0;
    for (int creature = 0; creature < m; ++creature) {
        ll sum = 0;
        while (idx >= 0 && sum < v) {
            sum += a[idx];
            --idx;
        }
        if (sum >= v) {
            sum_assigned += sum;
        } else {
            return -1;
        }
    }
    return total_sum - sum_assigned;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ll v;
        cin >> n >> m >> v;
        vector<int> a(n);
        ll total_sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total_sum += a[i];
        }
        ll alice_left = processLeftToRight(n, m, v, a, total_sum);
        ll alice_right = processRightToLeft(n, m, v, a, total_sum);
        if (alice_left == -1 && alice_right == -1) {
            cout << -1 << '\n';
        } else {
            cout << max(alice_left, alice_right) << '\n';
        }
    }
    return 0;
}
