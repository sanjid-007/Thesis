#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n <= 2) {
            // Impossible for strictly more than half to be unhappy
            std::cout << -1 << '\n';
            // Consume input
            for (int i = 0; i < n; ++i) {
                int tmp;
                std::cin >> tmp;
            }
            continue;
        }
        std::vector<int> a(n);
        ll S0 = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            S0 += a[i];
        }
        std::sort(a.begin(), a.end());
        int n_half = n / 2;
        int required_unhappy = n_half + 1;
        ll min_x = -1;
        for (int i = required_unhappy - 1; i < n; ++i) {
            ll ai = a[i];
            ll x_candidate = 2LL * n * ai - S0 + 1;
            if (x_candidate < 0) x_candidate = 0;
            if (min_x == -1 || x_candidate < min_x) {
                min_x = x_candidate;
            }
        }
        std::cout << min_x << '\n';
    }
    return 0;
}
