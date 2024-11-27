#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count1543(const vector<string>& carpet, int n, int m) {
    int count = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int layers = min(n, m) / 2;  // Number of layers

    for (int layer = 0; layer < layers; layer++) {
        string traversal = "";
        // Top row
        for (int j = layer; j < m - layer; j++) {
            traversal += carpet[layer][j];
            visited[layer][j] = true;
        }
        // Right column
        for (int i = layer + 1; i < n - layer; i++) {
            traversal += carpet[i][m - layer - 1];
            visited[i][m - layer - 1] = true;
        }
        // Bottom row
        for (int j = m - layer - 2; j >= layer; j--) {
            traversal += carpet[n - layer - 1][j];
            visited[n - layer - 1][j] = true;
        }
        // Left column
        for (int i = n - layer - 2; i > layer; i--) {
            traversal += carpet[i][layer];
            visited[i][layer] = true;
        }
        // Count "1543" in the current traversal
        size_t pos = 0;
        while ((pos = traversal.find("1543", pos)) != string::npos) {
            count++;
            pos++;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> carpet(n);
        for (int i = 0; i < n; i++) {
            cin >> carpet[i];
        }
        cout << count1543(carpet, n, m) << endl;
    }
    return 0;
}
