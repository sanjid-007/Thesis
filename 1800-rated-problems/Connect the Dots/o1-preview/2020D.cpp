#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Interval {
    int start, end;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<vector<Interval>>> intervals(11, vector<vector<Interval>>(11));

        for (int i = 0; i < m; ++i) {
            int ai, di, ki;
            cin >> ai >> di >> ki;
            // For di outside the range [1, 10], skip (though di is guaranteed to be within 1..10)
            if (di < 1 || di > 10) continue;

            int r = ai % di;
            if (r == di) r = 0;

            int start_s = ai;
            int end_s = ai + ki * di;
            if (end_s > n) end_s = n; // Ensure end_s does not exceed n

            int start_k = (start_s - r) / di;
            int end_k = (end_s - r) / di;

            intervals[di][r].push_back({start_k, end_k});
        }

        int total_connected_components = 0;

        for (int di = 1; di <= 10; ++di) {
            for (int r = 0; r < di; ++r) {
                // Calculate total positions in residue class
                int total_positions = (n - r) / di + 1;
                vector<Interval>& ivals = intervals[di][r];
                if (ivals.empty()) {
                    total_connected_components += total_positions;
                    continue;
                }
                // Sort intervals
                sort(ivals.begin(), ivals.end(), [](const Interval& a, const Interval& b) {
                    return a.start < b.start || (a.start == b.start && a.end < b.end);
                });

                // Merge intervals
                vector<Interval> merged_intervals;
                merged_intervals.push_back(ivals[0]);
                for (size_t i = 1; i < ivals.size(); ++i) {
                    Interval& last = merged_intervals.back();
                    if (ivals[i].start <= last.end + 1) {
                        last.end = max(last.end, ivals[i].end);
                    } else {
                        merged_intervals.push_back(ivals[i]);
                    }
                }

                // Calculate positions covered
                int positions_covered = 0;
                for (const auto& iv : merged_intervals) {
                    positions_covered += (iv.end - iv.start + 1);
                }
                int singleton_positions = total_positions - positions_covered;
                int connected_components = merged_intervals.size() + singleton_positions;
                total_connected_components += connected_components;
            }
        }
        cout << total_connected_components << '\n';
    }
    return 0;
}
