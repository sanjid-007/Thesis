#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canSatisfy(const vector<int>& a, int n, int m, int v, long long minSum) {
    int pieces = 0;
    long long currentSum = 0;

    for (int i = 0; i < n; i++) {
        currentSum += a[i];
        if (currentSum >= v) {
            pieces++;
            currentSum = 0;
        }
        if (pieces >= m) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, v;
        cin >> n >> m >> v;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        long long totalSum = accumulate(a.begin(), a.end(), 0LL);
        if (totalSum < 1LL * m * v) {
            cout << -1 << '\n';
            continue;
        }

        long long low = 0, high = totalSum, result = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (canSatisfy(a, n, m, v, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << result << '\n';
    }

    return 0;
}
