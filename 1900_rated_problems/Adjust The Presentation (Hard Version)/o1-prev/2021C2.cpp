#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> b(m);
        for (int &x : b) cin >> x;

        vector<pair<int, int>> updates(q);
        for (int i = 0; i < q; ++i) {
            cin >> updates[i].first >> updates[i].second;
            --updates[i].first; // zero-based index
        }

        vector<string> answers(q + 1);
        for (int upd = 0; upd <= q; ++upd) {
            list<int> lineup(a.begin(), a.end());
            unordered_map<int, list<int>::iterator> pos_map;
            for (auto it = lineup.begin(); it != lineup.end(); ++it) {
                pos_map[*it] = it;
            }

            bool possible = true;
            auto it = lineup.begin();
            for (int i = 0; i < m && possible; ++i) {
                int front_member = *it;
                if (front_member != b[i]) {
                    possible = false;
                    break;
                }
                // Remove front member
                it = lineup.erase(it);
                // Prepare for next slide
                if (i + 1 < m) {
                    int next_presenter = b[i + 1];
                    if (next_presenter == front_member) {
                        // Insert at front
                        lineup.insert(lineup.begin(), front_member);
                        it = lineup.begin();
                    } else if (pos_map.count(next_presenter)) {
                        // Insert after next_presenter
                        auto next_it = pos_map[next_presenter];
                        ++next_it;
                        auto inserted_it = lineup.insert(next_it, front_member);
                        it = lineup.begin();
                    } else {
                        possible = false;
                        break;
                    }
                    // Update positions in pos_map
                    pos_map[front_member] = lineup.begin();
                    auto temp_it = lineup.begin();
                    for (; temp_it != lineup.end(); ++temp_it) {
                        pos_map[*temp_it] = temp_it;
                    }
                }
            }
            answers[upd] = possible ? "YA" : "TIDAK";

            // Apply update
            if (upd < q) {
                int s = updates[upd].first;
                int t_mem = updates[upd].second;
                b[s] = t_mem;
            }
        }

        for (const string &ans : answers) {
            cout << ans << '\n';
        }
    }
    return 0;
}
