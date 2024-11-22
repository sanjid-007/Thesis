#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);

    // Read initial values and compute cumulative OR values
    vector<vector<int>> b(k); // b[j][i] = b_{i+1,j}
    for (int j = 0; j < k; ++j)
        b[j].resize(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            int a_ij;
            scanf("%d", &a_ij);
            if (i == 0)
                b[j][i] = a_ij;
            else
                b[j][i] = b[j][i - 1] | a_ij;
        }
    }

    int total_m = 0;
    for (int qi = 0; qi < q; ++qi) {
        int m;
        scanf("%d", &m);
        total_m += m;

        int L = 0, R = n - 1; // indices from 0 to n-1

        for (int mi = 0; mi < m; ++mi) {
            int r;
            char o[2];
            int c;
            scanf("%d %s %d", &r, o, &c);
            --r; // convert to 0-based index

            vector<int>& b_r = b[r];

            int l_i, r_i;

            if (o[0] == '<') {
                // b_{i,r} < c
                auto it = lower_bound(b_r.begin(), b_r.end(), c);
                int i0 = it - b_r.begin();
                l_i = 0;
                r_i = i0 - 1;
            } else {
                // b_{i,r} > c
                auto it = upper_bound(b_r.begin(), b_r.end(), c);
                int i0 = it - b_r.begin();
                l_i = i0;
                r_i = n - 1;
            }

            if (l_i > r_i) {
                L = 1;
                R = 0;
                break;
            }

            L = max(L, l_i);
            R = min(R, r_i);
        }

        if (L <= R) {
            printf("%d\n", L + 1);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
