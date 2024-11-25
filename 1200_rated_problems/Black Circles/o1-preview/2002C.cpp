#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> xi(n), yi(n);
        for (int i = 0; i < n; ++i) {
            cin >> xi[i] >> yi[i];
        }

        ll xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;

        long double dx = xt - xs;
        long double dy = yt - ys;
        long double Ds = sqrt(dx * dx + dy * dy);

        bool possible = true;

        for (int i = 0; i < n; ++i) {
            // Compute t_p
            long double numerator = (xi[i] - xs) * dx + (yi[i] - ys) * dy;
            long double denominator = dx * dx + dy * dy;
            long double tp = numerator / denominator;

            if (tp < 0.0L) tp = 0.0L;
            if (tp > 1.0L) tp = 1.0L;

            // Compute closest point P_p
            long double Px = xs + dx * tp;
            long double Py = ys + dy * tp;

            // Compute squared distance from circle center to P_p
            long double dp2 = (xi[i] - Px) * (xi[i] - Px) + (yi[i] - Py) * (yi[i] - Py);
            long double tp_t = Ds * tp;
            long double tp_t2 = tp_t * tp_t;

            if (dp2 <= tp_t2 + 1e-8L) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}
