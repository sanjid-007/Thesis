#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> parent, rank;
    stack<tuple<int, int, int, int>> history; // (u, parent_u, rank_u, mismatch_change)

    UnionFind(int n) {
        parent.resize(n+2);
        rank.resize(n+2, 0);
        for (int i = 0; i <= n+1; ++i) parent[i] = i;
    }

    int find(int u) {
        while (u != parent[u]) u = parent[u];
        return u;
    }

    void unite(int u, int v, int& mismatch_cnt, const vector<int>& p, const vector<int>& positions) {
        u = find(u);
        v = find(v);
        if (u == v) {
            history.push({-1, -1, -1, 0});
            return;
        }

        // Before union, check mismatches
        int mismatch_change = 0;
        if (positions[u] && positions[v]) {
            int pu = positions[u], pv = positions[v];
            if ((p[pu] != pu && find(p[pu]) != u) && (p[pv] != pv && find(p[pv]) == v)) mismatch_change -= 1;
            if ((p[pv] != pv && find(p[pv]) != v) && (p[pu] != pu && find(p[pu]) == u)) mismatch_change -= 1;
        }

        if (rank[u] < rank[v]) swap(u, v);
        history.push({v, parent[v], rank[u], mismatch_change});
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
        mismatch_cnt += mismatch_change;
    }

    void rollback() {
        auto [v, old_parent_v, old_rank_u, mismatch_change] = history.top();
        history.pop();
        if (v == -1) return;
        parent[v] = old_parent_v;
        rank[parent[v]] = old_rank_u;
        // mismatch_cnt is adjusted in the caller
    }
};

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> p(n+1), positions(n+2, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            positions[i] = i;
        }

        string s_input;
        cin >> s_input;
        s_input = ' ' + s_input; // 1-indexed

        vector<int> queries(q+1);
        for (int i = 1; i <= q; ++i) {
            cin >> queries[i];
        }

        // Build s for final state (after all queries)
        vector<char> s(n+1);
        for (int i = 1; i <= n; ++i) s[i] = s_input[i];

        for (int i = q; i >= 1; --i) {
            int idx = queries[i];
            s[idx] = (s[idx] == 'L') ? 'R' : 'L';
        }

        UnionFind uf(n);

        // Build UF for final state
        for (int i = 1; i <= n; ++i) {
            if (s[i] == 'L' && i >= 2) {
                uf.unite(i, i-1, n, p, positions); // mismatch_cnt is dummy here
            }
            if (s[i] == 'R' && i <= n-1) {
                uf.unite(i, i+1, n, p, positions);
            }
        }

        // Calculate initial mismatches
        int mismatch_cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (uf.find(p[i]) != uf.find(i)) {
                mismatch_cnt++;
            }
        }

        vector<string> ans(q+1);

        // Process queries in reverse
        for (int i = q; i >= 0; --i) {
            if (mismatch_cnt == 0) ans[i] = "YES";
            else ans[i] = "NO";

            if (i == 0) break; // No more queries to process

            int idx = queries[i];
            char prev_s = s[idx];
            s[idx] = (s[idx] == 'L') ? 'R' : 'L';

            // Undo the effect of toggling s[idx]
            if (prev_s == 'L') {
                if (idx >= 2) {
                    // Need to unite idx and idx-1
                    uf.unite(idx, idx-1, mismatch_cnt, p, positions);
                }
            } else {
                if (idx <= n-1) {
                    // Need to unite idx and idx+1
                    uf.unite(idx, idx+1, mismatch_cnt, p, positions);
                }
            }
        }

        // Output answers
        for (int i = 1; i <= q; ++i) {
            cout << ans[i] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
