#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, b, c;
        cin >> n >> b >> c;

        if (b == 0 && c == 0 && n > 1) {
            cout << -1 << endl;
            continue;
        }

        ll U = 0;
        if (b == 0) {
            if (c >= 0 && c <= n - 1) {
                U = 1;
            } else {
                U = 0;
            }
        } else {
            ll L = max(1LL, ((-c + b - 1) / b) + 1);
            ll R = min(n, ((n - 1 - c) / b) + 1);
            if (L > R) {
                U = 0;
            } else {
                U = R - L + 1;
            }
        }
        cout << n - U << endl;
    }
    return 0;
}
