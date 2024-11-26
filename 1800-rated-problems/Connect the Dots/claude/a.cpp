#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
    int components;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        components = n;
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if(px != py) {
            components--;
            if(rank[px] < rank[py]) {
                parent[px] = py;
            }
            else if(rank[px] > rank[py]) {
                parent[py] = px;
            }
            else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }
    
    int getComponents() {
        return components;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    DisjointSet ds(n);
    
    for(int i = 0; i < m; i++) {
        int a, d, k;
        cin >> a >> d >> k;
        
        // If k = 0, no points to connect
        if(k == 0) continue;
        
        // Connect all pairs of points in arithmetic sequence
        vector<int> points;
        for(int j = 0; j <= k; j++) {
            int point = a + j * d;
            if(point > n) break;
            points.push_back(point);
        }
        
        // Connect each point with every other point
        for(int j = 0; j < points.size(); j++) {
            for(int l = j + 1; l < points.size(); l++) {
                ds.unite(points[j], points[l]);
            }
        }
    }
    
    cout << ds.getComponents() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
