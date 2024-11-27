#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        long long b, c, d;
        cin >> b >> c >> d;
        
        long long a = 0;
        bool possible = true;
        
        for (int i = 0; i < 62; ++i) {
            int b_bit = (b >> i) & 1;
            int c_bit = (c >> i) & 1;
            int d_bit = (d >> i) & 1;
            
            if (d_bit == 0) {
                // If d_bit is 0, (a | b) - (a & c) must also result in 0
                if (b_bit == 1 && c_bit == 0) {
                    // Impossible to make this 0
                    possible = false;
                    break;
                }
                // Otherwise, set a_i = 0
            } else {
                // If d_bit is 1, (a | b) - (a & c) must result in 1
                if (b_bit == 0 && c_bit == 1) {
                    // Impossible to make this 1
                    possible = false;
                    break;
                }
                // Set a_i = 1
                a |= (1LL << i);
            }
        }
        
        if (possible) {
            cout << a << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
