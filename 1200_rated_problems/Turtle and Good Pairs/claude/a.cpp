#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Count frequency of each character
    vector<int> freq(26, 0);
    for(char c : s) {
        freq[c - 'a']++;
    }
    
    // First put characters that appear multiple times
    string result;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 1) {
            result.append(freq[i], char('a' + i));
            freq[i] = 0;
        }
    }
    
    // Then append remaining single occurrence characters
    // Try to put different characters next to each other when possible
    string remaining;
    for(int i = 0; i < 26; i++) {
        if(freq[i] == 1) {
            remaining += char('a' + i);
        }
    }
    
    // If we have remaining characters, try to maximize pleasant pairs
    // by alternating them when possible
    if(!remaining.empty()) {
        sort(remaining.begin(), remaining.end());
        string temp;
        int mid = (remaining.size() + 1) / 2;
        
        // Place characters alternately from start and end
        for(int i = 0; i < mid && i < remaining.size(); i++) {
            temp += remaining[i];
            if(mid + i < remaining.size()) {
                temp += remaining[mid + i];
            }
        }
        
        result += temp;
    }
    
    cout << result << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
