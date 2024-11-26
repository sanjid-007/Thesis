#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int w;
    cin >> w;
    vector<ll> heights(w);
    for(int i = 0; i < w; i++) {
        cin >> heights[i];
    }
    
    // Sort heights in descending order to place largest gorillas first
    sort(heights.begin(), heights.end(), greater<ll>());
    
    // Calculate how many sub-squares cover each cell
    vector<vector<int>> coverage(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            // For each cell, count how many k×k squares can cover it
            int min_row = max(0, i - k + 1);
            int max_row = min(n - k, i);
            int min_col = max(0, j - k + 1);
            int max_col = min(m - k, j);
            
            coverage[i][j] = (max_row - min_row + 1) * (max_col - min_col + 1);
        }
    }
    
    // Create vector of cell positions with their coverage
    vector<pair<int, pair<int, int>>> cells;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cells.push_back({coverage[i][j], {i, j}});
        }
    }
    
    // Sort cells by coverage in descending order
    sort(cells.begin(), cells.end(), greater<pair<int, pair<int, int>>>());
    
    // Place gorillas in grid
    vector<vector<ll>> grid(n, vector<ll>(m, 0));
    for(int i = 0; i < w; i++) {
        int row = cells[i].second.first;
        int col = cells[i].second.second;
        grid[row][col] = heights[i];
    }
    
    // Calculate total spectacle
    ll result = 0;
    for(int i = 0; i <= n-k; i++) {
        for(int j = 0; j <= m-k; j++) {
            ll square_sum = 0;
            // Sum up the k×k square starting at (i,j)
            for(int x = i; x < i+k; x++) {
                for(int y = j; y < j+k; y++) {
                    square_sum += grid[x][y];
                }
            }
            result += square_sum;
        }
    }
    
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
