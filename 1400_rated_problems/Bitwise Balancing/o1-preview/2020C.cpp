#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ull b, c, d;
        cin >> b >> c >> d;
        ull a = 0;
        int borrow_in = 0;
        bool possible = true;
        for (int i = 0; i <= 61; ++i) {
            int b_i = (b >> i) & 1;
            int c_i = (c >> i) & 1;
            int d_i = (d >> i) & 1;
            int possible_u = -1;
            int borrow_out = -1;

            // Try u_i = 0
            for (int u_i = 0; u_i <= 1; ++u_i) {
                int s_i = u_i | b_i;
                int t_i = u_i & c_i;
                int diff = s_i - t_i - borrow_in;
                int new_borrow_out = 0;
                if (diff < 0) {
                    diff += 2;
                    new_borrow_out = 1;
                }
                if (diff == d_i) {
                    possible_u = u_i;
                    borrow_out = new_borrow_out;
                    break; // We can break here because any valid u_i is acceptable
                }
            }

            if (possible_u == -1) {
                possible = false;
                break;
            }

            if (possible_u == 1) {
                a |= (1ULL << i);
            }
            borrow_in = borrow_out;
        }
        if (!possible || borrow_in != 0) {
            cout << -1 << '\n';
        } else {
            cout << a << '\n';
        }
    }
    return 0;
}
