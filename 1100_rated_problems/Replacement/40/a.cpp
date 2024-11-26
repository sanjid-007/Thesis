#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canWinGame(string &s, string &r, int n) {
    for (int i = 0; i < n - 1; i++) {
        bool found = false;
        for (int j = 0; j < s.size() - 1; j++) {
            if (s[j] != s[j + 1]) {
                s[j] = r[i];
                s.erase(s.begin() + j + 1);
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s, r;
        cin >> s >> r;
        cout << (canWinGame(s, r, n) ? "YES" : "NO") << endl;
    }
    return 0;
}
