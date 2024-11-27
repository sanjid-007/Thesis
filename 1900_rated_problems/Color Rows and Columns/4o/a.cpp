#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> rectangles(n);
        for (int i = 0; i < n; ++i) {
            cin >> rectangles[i].first >> rectangles[i].second;
        }

        vector<int> max_points;
        for (const auto& rect : rectangles) {
            int a = rect.first, b = rect.second;
            max_points.push_back(max(a, b));
        }

        sort(max_points.rbegin(), max_points.rend());

        int operations = 0, points = 0;
        for (int i = 0; i < max_points.size() && points < k; ++i) {
            points += max_points[i];
            operations += max_points[i];
        }

        if (points < k) {
            cout << -1 << endl;
        } else {
            cout << operations << endl;
        }
    }
    return 0;
}
