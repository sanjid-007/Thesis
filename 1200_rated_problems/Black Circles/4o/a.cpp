#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;

struct Circle {
    int x, y;
};

bool isPossible(const vector<Circle>& circles, int xs, int ys, int xt, int yt) {
    int n = circles.size();
    vector<int> parent(n + 2, -1);

    auto find = [&](int u) {
        while (parent[u] != -1) {
            u = parent[u];
        }
        return u;
    };

    auto unite = [&](int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            parent[pu] = pv;
        }
    };

    auto distanceSquared = [&](int x1, int y1, int x2, int y2) {
        return 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2);
    };

    vector<pair<int, int>> points(n + 2);
    points[0] = {xs, ys};
    points[n + 1] = {xt, yt};

    for (int i = 0; i < n; i++) {
        points[i + 1] = {circles[i].x, circles[i].y};
    }

    vector<vector<int>> connected(n + 2);

    for (int i = 0; i < n + 2; i++) {
        for (int j = i + 1; j < n + 2; j++) {
            long long d = distanceSquared(points[i].first, points[i].second, points[j].first, points[j].second);
            if (d <= 1LL) {
                unite(i, j);
            }
        }
    }

    return find(0) != find(n + 1);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<Circle> circles(n);
        for (int i = 0; i < n; i++) {
            cin >> circles[i].x >> circles[i].y;
        }
        int xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;
        cout << (isPossible(circles, xs, ys, xt, yt) ? "YES" : "NO") << endl;
    }
    return 0;
}
