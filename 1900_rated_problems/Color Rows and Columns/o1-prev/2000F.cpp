#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_K = 100;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> dp(MAX_K + 201, INT_MAX);
        dp[0] = 0;

        for (int rect = 0; rect < n; ++rect) {
            int ai, bi;
            cin >> ai >> bi;

            int maxPoints = ai + bi;
            int maxS = min(MAX_K + 200, maxPoints);

            vector<int> new_dp(dp);

            // Option 1: Filling Rows
            for (int s = 1; s <= min(bi, MAX_K); ++s) {
                int cost = s * ai;
                for (int j = MAX_K; j >= s; --j) {
                    if (dp[j - s] != INT_MAX) {
                        new_dp[j] = min(new_dp[j], dp[j - s] + cost);
                    }
                }
            }

            // Option 2: Filling Columns
            for (int s = 1; s <= min(ai, MAX_K); ++s) {
                int cost = s * bi;
                for (int j = MAX_K; j >= s; --j) {
                    if (dp[j - s] != INT_MAX) {
                        new_dp[j] = min(new_dp[j], dp[j - s] + cost);
                    }
                }
            }

            // Option 3: Filling Both Rows and Columns
            if (ai + bi <= MAX_K) {
                int s = ai + bi;
                int cost = ai * bi;
                for (int j = MAX_K; j >= s; --j) {
                    if (dp[j - s] != INT_MAX) {
                        new_dp[j] = min(new_dp[j], dp[j - s] + cost);
                    }
                }
                // Also, direct assignment if dp[0] is valid
                if (dp[0] != INT_MAX) {
                    new_dp[s] = min(new_dp[s], dp[0] + cost);
                }
            }

            dp.swap(new_dp);
        }

        int ans = INT_MAX;
        for (int s = k; s <= MAX_K; ++s) {
            if (dp[s] != INT_MAX) {
                ans = min(ans, dp[s]);
            }
        }
        if (ans == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
