#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q; // q is zero as per problem statement
        vector<int> lineup(n);
        unordered_map<int, int> pos; // member -> position
        for (int i = 0; i < n; ++i) {
            cin >> lineup[i];
            pos[lineup[i]] = i;
        }
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        bool possible = true;
        for (int i = 0; i < m; ++i) {
            int front_member = lineup[0];
            int required_member = b[i];
            if (front_member == required_member) {
                // Do nothing, proceed to next slide
            } else {
                int pos_bi = pos[required_member];
                int pos_front = pos[front_member];
                if (pos_bi > pos_front) {
                    // Move front member to after required member
                    // Shift members between front and required member
                    for (int j = pos_front; j < pos_bi; ++j) {
                        lineup[j] = lineup[j + 1];
                        pos[lineup[j]] = j;
                    }
                    lineup[pos_bi] = front_member;
                    pos[front_member] = pos_bi;
                } else {
                    // Cannot bring required member to front
                    possible = false;
                    break;
                }
            }
            // Move front member to any position (does not affect our logic)
            // Simulate by removing front member
            int front_member_new_pos = pos[lineup[0]]; // updated position after previous operations
            lineup.erase(lineup.begin());
            // For simplicity, insert at end
            lineup.push_back(front_member);
            pos[front_member] = lineup.size() - 1;
            // Update positions of all members
            for (int j = 0; j < lineup.size(); ++j) {
                pos[lineup[j]] = j;
            }
        }
        cout << (possible ? "YA" : "TIDAK") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
