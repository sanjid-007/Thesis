#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Disjoint Set Union (Union-Find) implementation
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        DSU dsu(n);
        for (int i = 0; i < m; ++i) {
            int a, d, k;
            cin >> a >> d >> k;
            vector<int> points;
            for (int j = 0; j <= k; ++j) {
                points.push_back(a + j * d);
            }
            for (int j = 1; j < points.size(); ++j) {
                dsu.unite(points[j - 1], points[j]);
            }
        }

        set<int> uniqueComponents;
        for (int i = 1; i <= n; ++i) {
            uniqueComponents.insert(dsu.find(i));
        }

        cout << uniqueComponents.size() << "\n";
    }

    return 0;
}
