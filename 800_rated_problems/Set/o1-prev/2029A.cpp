#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long l, r, k;
        cin >> l >> r >> k;

        long long max_x = r / k;
        if (max_x < l) {
            cout << 0 << '\n';
        } else {
            long long ans = min(r, max_x) - l + 1;
            cout << ans << '\n';
        }
    }
    return 0;
}
