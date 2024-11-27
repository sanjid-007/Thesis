#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long calculate_difference(vector<long long>& a, int n) {
    long long min_value = a[0], max_value = a[0];
    for (int i = 1; i < n; i++) {
        min_value = min(min_value, a[i]);
        max_value = max(max_value, a[i]);
    }
    return max_value - min_value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Two observations based on the operations allowed
        long long result = calculate_difference(a, n); // Max difference initially
        
        for (int i = 0; i < n - 1; i++) {
            result = min(result, abs(a[i + 1] - a[i])); // Adjacent difference
        }

        // Boundary cases
        result = min(result, a[n - 1] - a[0]);

        cout << result << '\n';
    }

    return 0;
}
