#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

typedef long long ll;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> columns;
        vector<int> rows;
        int chips_in_row1 = 0, chips_in_row2 = 0;
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '*') {
                columns.push_back(i);
                rows.push_back(1);
                ++chips_in_row1;
            }
            if (s2[i] == '*') {
                columns.push_back(i);
                rows.push_back(2);
                ++chips_in_row2;
            }
        }
        int total_chips = columns.size();
        if (total_chips <= 1) {
            cout << 0 << '\n';
            continue;
        }
        // Sort columns for prefix sums
        vector<int> sorted_columns = columns;
        sort(sorted_columns.begin(), sorted_columns.end());
        vector<ll> prefix_sum(total_chips + 1, 0);
        for (int i = 0; i < total_chips; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + sorted_columns[i];
        }
        ll min_total_moves = LLONG_MAX;
        // Try target row 1 and row 2
        for (int target_row = 1; target_row <= 2; ++target_row) {
            int vertical_moves = (target_row == 1) ? chips_in_row2 : chips_in_row1;
            // Try possible target columns (positions where chips are located)
            for (int i = 0; i < total_chips; ++i) {
                int c = sorted_columns[i];
                // Total horizontal moves
                // Left side
                ll left_count = i;
                ll left_sum = prefix_sum[i];
                ll cost_left = c * left_count - left_sum;
                // Right side
                ll right_count = total_chips - i - 1;
                ll right_sum = prefix_sum[total_chips] - prefix_sum[i + 1];
                ll cost_right = right_sum - c * right_count;
                ll total_horizontal_moves = cost_left + cost_right;
                ll total_moves = vertical_moves + total_horizontal_moves;
                if (total_moves < min_total_moves) {
                    min_total_moves = total_moves;
                }
            }
        }
        cout << min_total_moves << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
