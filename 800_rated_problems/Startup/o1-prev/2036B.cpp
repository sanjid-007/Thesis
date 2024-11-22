#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_K = 2e5 + 5;
long long total_cost_per_brand[MAX_K];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> brands_list; // To keep track of brands used in each test case

    while (t--) {
        int n, k;
        cin >> n >> k;
        brands_list.clear();

        for (int i = 0; i < k; ++i) {
            int bi, ci;
            cin >> bi >> ci;
            if (total_cost_per_brand[bi] == 0) {
                brands_list.push_back(bi);
            }
            total_cost_per_brand[bi] += ci;
        }

        vector<long long> total_costs;
        for (int bi : brands_list) {
            total_costs.push_back(total_cost_per_brand[bi]);
            total_cost_per_brand[bi] = 0; // Reset for next test case
        }

        sort(total_costs.rbegin(), total_costs.rend());

        int m = min(n, (int)total_costs.size());
        long long answer = 0;
        for (int i = 0; i < m; ++i) {
            answer += total_costs[i];
        }

        cout << answer << '\n';
    }

    return 0;
}
