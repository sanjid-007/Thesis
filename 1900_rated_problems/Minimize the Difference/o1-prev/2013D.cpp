#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int64_t n;
        cin >> n;
        vector<int64_t> a(n);
        for (int64_t i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Adjust the array from left to right
        for (int64_t i = 0; i < n - 1; ++i) {
            if (a[i + 1] <= a[i]) {
                a[i + 1] = a[i] + 1;
            }
        }

        int64_t min_val = a[0];
        int64_t max_val = a[n - 1];
        int64_t result = max_val - min_val;

        // Check if the minimal possible difference is less than n - 1
        result = min(result, n - 1);

        cout << result << '\n';
    }

    return 0;
}
