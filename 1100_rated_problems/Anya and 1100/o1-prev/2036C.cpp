#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string s_input;
        cin >> s_input;
        int n = s_input.size();
        vector<char> s(n);
        for (int i = 0; i < n; ++i) {
            s[i] = s_input[i];
        }
        int cnt1100 = 0;
        // Preprocess the initial count of "1100"
        for (int i = 0; i <= n - 4; ++i) {
            if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0') {
                cnt1100++;
            }
        }
        int q;
        cin >> q;
        while (q--) {
            int i;
            char v_char;
            cin >> i >> v_char;
            char v = v_char; // Since v is '0' or '1'
            i--; // Adjust for 0-based indexing
            // For positions from i-3 to i
            for (int j = max(0, i - 3); j <= min(n - 4, i); ++j) {
                // Check if "1100" existed before the change
                if (s[j] == '1' && s[j+1] == '1' && s[j+2] == '0' && s[j+3] == '0') {
                    cnt1100--;
                }
            }
            // Apply the change
            s[i] = v;
            // Check again after the change
            for (int j = max(0, i - 3); j <= min(n - 4, i); ++j) {
                if (s[j] == '1' && s[j+1] == '1' && s[j+2] == '0' && s[j+3] == '0') {
                    cnt1100++;
                }
            }
            if (cnt1100 > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
