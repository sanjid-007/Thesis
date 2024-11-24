#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Swap {
    long long d_i;
    long long Delta_i;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        // Sort in decreasing order
        sort(a.begin(), a.end(), greater<long long>());

        // Initial score
        long long initial_score = 0;
        long long Alice_total = 0, Bob_total = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)
                Alice_total += a[i];
            else
                Bob_total += a[i];
        }
        initial_score = Alice_total - Bob_total;

        // Collect possible swaps
        vector<Swap> swaps;
        for (int i = 1; i < n; i += 2) { // Bob's turns
            long long c_prev = a[i - 1]; // Alice's item
            long long c_curr = a[i];     // Bob's item
            long long d_i = c_prev - c_curr + 1;
            if (d_i > 2) {
                Swap sw;
                sw.d_i = d_i;
                sw.Delta_i = 2 - d_i;
                swaps.push_back(sw);
            }
        }

        // Sort swaps in decreasing order of d_i
        sort(swaps.begin(), swaps.end(), [](const Swap &a, const Swap &b) {
            return a.d_i > b.d_i;
        });

        long long total_d = 0;
        long long total_Delta = 0;
        long long min_final_score = initial_score;

        for (const auto &sw : swaps) {
            if (total_d + sw.d_i <= k) {
                total_d += sw.d_i;
                total_Delta += sw.Delta_i;
                long long final_score = initial_score + total_Delta;
                if (final_score < min_final_score) {
                    min_final_score = final_score;
                }
            } else {
                break;
            }
        }

        cout << min_final_score << '\n';
    }

    return 0;
}
