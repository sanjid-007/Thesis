#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countOccurrences(const string& path, const string& pattern) {
    int count = 0;
    size_t pos = path.find(pattern);
    while (pos != string::npos) {
        count++;
        pos = path.find(pattern, pos + 1);
    }
    return count;
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m; // Dimensions of the grid
        vector<string> grid(n);

        // Read the grid
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        int total_count = 0;
        int layers = min(n, m) / 2; // Calculate the number of layers

        for (int l = 0; l < layers; ++l) {
            string path;

            int top = l;
            int bottom = n - 1 - l;
            int left = l;
            int right = m - 1 - l;

            // Top Row (Left to Right)
            for (int c = left; c <= right; ++c) {
                path += grid[top][c];
            }

            // Right Column (Top to Bottom)
            for (int r = top + 1; r <= bottom; ++r) {
                path += grid[r][right];
            }

            // Bottom Row (Right to Left), only if top and bottom are not the same
            if (bottom != top) {
                for (int c = right - 1; c >= left; --c) {
                    path += grid[bottom][c];
                }
            }

            // Left Column (Bottom to Top), only if left and right are not the same
            if (right != left) {
                for (int r = bottom - 1; r > top; --r) {
                    path += grid[r][left];
                }
            }

            // Count occurrences of "1543" in the path
            int count = 0;
            for (size_t i = 0; i + 3 < path.size(); ++i) {
                if (path.substr(i, 4) == "1543") {
                    count++;
                }
            }

            total_count += count;
        }

        cout << total_count << endl;
    }

    return 0;
}
