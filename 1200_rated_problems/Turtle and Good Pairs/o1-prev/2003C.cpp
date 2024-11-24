#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int getMaxFreqIndex(vector<int>& freq) {
    int maxFreq = -1, index = -1;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            index = i;
        }
    }
    return index;
}

int getNextMaxFreqIndex(vector<int>& freq, int excludeIndex) {
    int maxFreq = -1, index = -1;
    for (int i = 0; i < 26; ++i) {
        if (i != excludeIndex && freq[i] > maxFreq) {
            maxFreq = freq[i];
            index = i;
        }
    }
    return index;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string res = "";
        while (true) {
            int totalChars = 0;
            for (int f : freq) totalChars += f;
            if (totalChars == 0) break;

            int c1 = getMaxFreqIndex(freq);
            if (freq[c1] == 0) break;
            res += (char)(c1 + 'a');
            freq[c1]--;

            int c2 = getNextMaxFreqIndex(freq, -1);
            if (freq[c2] > 0) {
                res += (char)(c2 + 'a');
                freq[c2]--;
            }
        }
        cout << res << endl;
    }
}

int main() {
    solve();
    return 0;
}
