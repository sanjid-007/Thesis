#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <numeric>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> freq;
        for (int &x : a) {
            cin >> x;
            freq[x]++;
        }

        // Get unique elements and sort by frequency
        vector<pair<int, int>> freq_vec(freq.begin(), freq.end());
        sort(freq_vec.begin(), freq_vec.end(), [](const pair<int,int> &a, const pair<int,int> &b){
            return a.second > b.second;
        });

        int K = min(10, (int)freq_vec.size());
        vector<int> top_values;
        for (int i = 0; i < K; ++i) {
            top_values.push_back(freq_vec[i].first);
        }

        int min_operations = n;
        set<int> best_combination;

        // Generate combinations of 3 values
        for (int i = 0; i < top_values.size(); ++i) {
            for (int j = i; j < top_values.size(); ++j) {
                for (int k = j; k < top_values.size(); ++k) {
                    int x = top_values[i];
                    int y = top_values[j];
                    int z = top_values[k];
                    // Check triangle inequality
                    if (x + y > z && y + z > x && z + x > y) {
                        set<int> values = {x, y, z};
                        int operations = n;
                        for (int val : values) {
                            operations -= freq[val];
                        }
                        if (operations < min_operations) {
                            min_operations = operations;
                            best_combination = values;
                        }
                    }
                }
            }
        }

        // If no valid combination found, try combinations of 2 values
        if (best_combination.empty()) {
            for (int i = 0; i < top_values.size(); ++i) {
                for (int j = i; j < top_values.size(); ++j) {
                    int x = top_values[i];
                    int y = top_values[j];
                    if (x + x > y && x + y > x && y + y > x) {
                        set<int> values = {x, y};
                        int operations = n;
                        for (int val : values) {
                            operations -= freq[val];
                        }
                        if (operations < min_operations) {
                            min_operations = operations;
                            best_combination = values;
                        }
                    }
                }
            }
        }

        // If still no valid combination, use the most frequent value
        if (best_combination.empty()) {
            int max_freq = freq_vec[0].second;
            min_operations = n - max_freq;
        }

        cout << min_operations << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
