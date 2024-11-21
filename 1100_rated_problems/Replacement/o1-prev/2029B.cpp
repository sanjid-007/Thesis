#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s, r;
        cin >> n >> s >> r;

        int total_differences = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] != s[i + 1]) {
                total_differences++;
            }
        }

        int required_differences = max(1, n - 2);

        if (total_differences >= required_differences) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
