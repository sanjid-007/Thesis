#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // Count frequency of each character
        vector<pair<char, int>> freq(26);
        for (int i = 0; i < 26; ++i) {
            freq[i] = {char('a' + i), 0};
        }

        for (char c : s) {
            freq[c - 'a'].second++;
        }

        // Sort characters by frequency
        sort(freq.rbegin(), freq.rend(), [](const pair<char, int> &a, const pair<char, int> &b) {
            return a.second < b.second;
        });

        // Construct the reordered string
        string result;
        for (auto &f : freq) {
            result += string(f.second, f.first);
        }

        cout << result << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
